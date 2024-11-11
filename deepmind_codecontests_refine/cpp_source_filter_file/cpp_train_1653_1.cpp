#include<iostream>
using namespace std;
int main(void)
{
int x;
while(cin>>x)
{
int a[10]={1,2,4,8,16,32,64,128,256,512};
int b[10]={0};

int j=0;
for(int i=9;i>=0;i--)
{
	if(x>=a[i])
	{
	x-=a[i];
	b[j]=a[i];
	j++;
	if(x==0)break;
	}
}
for(int i=9;i>=0;i--)
{
(b[i]!=0)cout<<b[i]<<(i==0?"\n":" ");
}
}
return 0;
}