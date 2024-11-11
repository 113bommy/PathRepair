#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+50;
struct node{
	int a,b;
}c[maxn];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i].a>>c[i].b;
	}
	sort(c,c+n,cmp);
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(t+c[i].a<=c[i].b)
		{
			t+=c[i].a;
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}