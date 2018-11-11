#include<stdio.h>
#include<conio.h>
#include<bios.h>
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define DIM 7
#define WIDTH 5
#define HEIGHT 1
#define VL 179
#define HL 196
#define LT 218
#define RT 191
#define LB 192
#define RB 217
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define CROSS 197
#define BS 8
#define SP 32
#define LEFT 19200
#define RIGHT 19712
#define UP 18432
#define DOWN 20480
#define ESC 283
#define HOME 18176
#define END 20224
int isLeapyear(int y)
	{
		if(y%4==0)
		{
			if(y%100==0)
			{
				if(y%400 == 0)
					return 1;
				else
					return 0;
			}
			else
				return 1;
		}
		else
			return 0;

	}
	int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int dayOfDate(int eDate,int eMonth,int eYear)
{       int sDate=1, sMonth=1, sYear=1900;
	int Mdays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	long int day=0,day_sum=0,yr,i;
	for(i=sMonth;i<=12;i++)
	{
	       day_sum+=Mdays[i];
	}
	day_sum=day_sum - sDate+1;
	if(sMonth <= 2)
	{
	       day_sum+=isLeapyear(sYear);
	}
	for(i=1;i<eMonth;i++)
	{
		day_sum+=Mdays[i];
	}
	day_sum=day_sum+eDate;
	if(eMonth > 2)
	{
	       day_sum+=isLeapyear(eYear);
	}
	for(i=sYear+1;i<eYear;i++)
	{
		day_sum+=365+isLeapyear(i);
	}
	day=day_sum%7;
	return day;
}
int drawDabba()
{
int bcol,brow,count3,count1,count2;
clrscr();
bcol=(80-((DIM*WIDTH)+DIM+1))/2;
brow=(25-((DIM*HEIGHT)+DIM+1))/2;
gotoxy(bcol,brow);
printf("%c",LT);
for(count2=1;count2<=DIM;count2++)
{
		for(count1=1;count1<=WIDTH;count1++)
		{
			printf("%c",HL);
		}
	printf("%c",TT);
}
printf("%c%c",BS,RT);
//end of the first line
for(count3=1;count3<=DIM;count3++)
{
	gotoxy(bcol,++brow);
	for(count2=1;count2<=DIM+1;count2++)
	{
		printf("%c",VL);
		       for(count1=1;count1<=WIDTH;count1++)
		       {
			     printf(" ");
			}
	}
//end of the second line
	gotoxy(bcol,++brow);
	printf("%c",LST);
	for(count2=1;count2<=DIM;count2++)
	{

		  for(count1=1;count1<=WIDTH;count1++)
			{
				printf("%c",HL);
			}
			printf("%c",CROSS);
	}
	printf("%c%c",BS,RST);

}
gotoxy(bcol,brow);
	printf("%c",LB);
	for(count2=1;count2<=DIM;count2++)
	{

		  for(count1=1;count1<=WIDTH;count1++)
			{
				printf("%c",HL);
			}
			printf("%c",BT);
	}
	printf("%c%c",BS,RB);
}
fillDabba(int ed,int em,int ey)
{
 int bcol,brow,col,row,date,dayno,dateLimit;
 bcol=(80-((DIM*WIDTH)+DIM+1))/2;
 brow=(25-((DIM*HEIGHT)+DIM+1))/2;
 gotoxy(18,4);
 printf("%d,%d",em,ey);
 col = bcol+2;
 row=brow+1;
 gotoxy(col,row);
 printf("SUN");
 gotoxy(col+6,row);
 printf("MON");
 gotoxy(col+12,row);
 printf("TUE");
 gotoxy(col+18,row);
 printf("WED");
 gotoxy(col+24,row);
 printf("THU");
 gotoxy(col+30,row);
 printf("FRI");
 gotoxy(col+36,row);
 printf("SAT");
  col = bcol+3;
  row=brow+3;
  dayno=dayOfDate(ed,em,ey);
dateLimit = mon[em];
if(em==2)
  dateLimit+=isLeapyear(ey);
for( date=1;date<=dateLimit;date++)
{   gotoxy(col+dayno*(WIDTH+1),row);
   printf("%d",date);
    dayno++;
    if(dayno==7)
    {
     dayno=0;
     row+=HEIGHT+1;
     }
}
}
 int main()
 {
  int d=1,m=1,y=2018,key;
  clrscr();
  do
  {
  drawDabba();
  fillDabba(d,m,y);
  while(bioskey(1)==0); //watchman
  key=bioskey(0);//receptionsit
  switch(key)
  {
   case LEFT:   m--;
		if(m==0)
		{
		m=12;
		y--;
		}
		break;
   case RIGHT:  m++;
		if(m==13)
		{
		m=1;
		y++;
		}
		break;
   case UP:     y--;
		break;
   case DOWN:   y++;
		break;
  }
  }while(key!=ESC);

  getch();
 }
