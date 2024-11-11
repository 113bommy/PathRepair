#include<iostream>
using namespace std;
unsigned long long int f[90];
int main()
{
	int n;
	cin>>n;
	f[0]=2;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=tui[i-1]+f[i-2];
	}
	cout<<f[n];
}