#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s,c,a[100];
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		cin>>s>>c;
		if(a[s]!=-1&&a[s]!=c)
		{
			cout<<-1<<endl;
			return 0;
		}
		else a[s]=c; 
	}
	if(n>1&&a[1]==0)
	cout<<-1<<endl;
	else if(n==1)
	{
		if(a[1]==-1)
		cout<<0<<endl;
		else
		cout<<a[1]<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
		if(i==1&&a[i]==-1)
		cout<<1;
		else if(a[i]==-1)
		cout<<0;
		else
		cout<<a[i];	
		}
	}
	return 0;
}