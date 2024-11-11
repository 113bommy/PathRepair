#include<iostream>
using namespace std;
int n,m,i;
int a[55],b[55],c[55];
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		c[a[i]]++;
		c[b[i]]++;
	}	
	for(i=1;i<=n;i++)
	{
		cout<<c[i]<<endl;
	}
	return 0;
} 