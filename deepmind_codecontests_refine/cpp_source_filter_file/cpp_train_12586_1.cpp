#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int temp,n,k,t[100000],m,s[100000];
	cin>>n>>k;
	m=n;
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
	}
	for(int i=0;i<n-1;i++)
	{
		s[i]=t[i+1]-t[i]-1;
	}

	sotr( s ,s + n - 1 ) ;

	for(int i=0;i<n-k;i++)
	{
		m+=s[i];
	}
	cout<<m<<endl;	
	return 0;
}
