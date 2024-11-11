#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[101010],b[101010],c[101010],p[101010];
long long ans;
set<int>st;
int zg(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=zg[p[x]];
	return p[x];
}
void gz(int x,int y)
{
	x=zg(x);
	y=zg(y);
	if(x!=y)
	{
		p[x]=y;
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		p[i]=i;
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		if(c[i]==0)
		{
			gz(a[i],b[i]);
		}
	}
	for(int i=0;i<q;i++)
	{
		if(c[i]==1)
		{
			if(m==n-1)
			{
				cout<<"No"<<endl;
				return 0;
			}
			if(zg(a[i])==zg(b[i]))
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	ans=n-1;
	for(int i=0;i<n;i++)
	{
		st.insert(zg(i));
	}
	long long sz=st.size();
	ans+=sz*(sz-1)/2-sz+1;
	if(ans<m)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	return 0;
}