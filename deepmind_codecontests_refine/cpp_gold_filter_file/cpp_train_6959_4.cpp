#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n;
	int m,i,x,j,y;
	cin>>n;
	m=sqrt(n);
	for(i=m;i>=1;i--)if(n%i==0){x=i;break;}
	y=n/i;
	for(i=0;x!=0;i++)x=x/10;
	for(j=0;y!=0;j++)y=y/10;
	cout<<max(i,j)<<endl;
	return 0;
}