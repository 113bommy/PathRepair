#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int a,za,shu,s=0;
	cin>>a;
	za=sqrt(a);
	for(int i=za;i>0;--i)
	{
		if(a%i==0)
		{
			shu=n/i;
			break;
		}
	}
	while(shu>0)
	{
		++s;
		shu/=10;
	}
	cout<<s<<endl;
	return 0;
}