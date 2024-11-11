#include<bits/stdc++.h>
using namespace std;
struct bracket
{
	int a,b;
}c[1000005],d[1000005];
bool cmp(bracket x,bracket y)
{
	return x.a+x.b>y.a+y.b;
}
bool cmp2(bracket x,bracket y)
{
	return x.b<y.b;
}
int main()
{
	int n,cnt1=0,cnt2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t=0,maxt=0;
		char ch=getchar();
		while(ch!=')'&&ch!='(')ch=getchar();
		while(ch=='('||ch==')')
		{
			if(ch=='(')t++;
			else t--;
			maxt=max(maxt,-t);
			ch=getchar();
		}
		if(t>=0)c[++cnt1].a=t,c[cnt1].b=maxt;
		else d[++cnt2].a=t,d[cnt2].b=max(-t,maxt);
	}
	sort(c+1,c+cnt1+1,cmp2);
	int now=0;
	for(int i=1;i<=cnt1;i++)
	if(c[i].b>now)
	{
		puts("No");
		return 0;
	}
	else now+=c[i].a;
	sort(d+1,d+cnt2+1,cmp);
	for(int i=1;i<=cnt2;i++)
		if(d[i].b>now)
		{
			puts("No");
			return 0;
		}
		else now+=d[i].a;
	if(now)puts("No");
	else puts("Yes");
	return 0;
}