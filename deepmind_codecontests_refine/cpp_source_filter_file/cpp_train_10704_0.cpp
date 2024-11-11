#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i=0,e=0,w=0,an=1e9,a[300003];
	char c[300003];
	cin>>n;
	for(;i<n;)
	{
		cin>>c[i];
		a[i]=cw;
		w+=c[i++]==87;
	}
	for(;i>0;)
	{
		an=min(an,a[i]+e);
		e+=c[--i]==69;
	}
	cout<<an<<endl;
}