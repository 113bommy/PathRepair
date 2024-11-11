#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PA pair<ll,ll>
const int mod = 1000000007;
vector<PA >a[110];
ll f[110];
int Q;
void init()
{
	a[1].push_back(PA(1,1));
	f[0]=f[1]=1;
	for(int i=2;i<=90;i++)
		f[i]=f[i-1]+f[i-2];
	for(int i=2;i<90;i++)
	{
		a[i].push_back(PA(f[i-1],f[i]));
		a[i].push_back(PA(f[i-1],f[i+1]));
		for(int j=1;j<a[i-1].size();j++)
		{
			PA t=a[i-1][j];
			a[i].push_back(PA(t.second,t.first+t.second));
		}
	}
}
int main()
{
	//freopen("tt.in","r",stdin);
	init();
	scanf("%d",&Q);
	while(Q--)
	{
		ll x,y,ans=0;
		scanf("%lld%lld",&x,&y);
		if(x>y)swap(x,y);
		if(x==1)
		{
			printf("1 %lld\n",y%mod);
			continue;
		}
		if(x==2&&y==2)
		{
			puts("1 4");
			continue;
		}
		int k=upper_bound(f+1,f+90+1,x)-f;
		k=min(k,upper_bound(f+1,f+90+1,y)-f-1);
		
		for(int i=0;i<a[k-1].size();i++)
		{
			PA t=a[k-1][i];
			if(t.second<=x)
			{
				ans+=(y-t.first)/t.second;
				ans+=(x-t.first)/t.second;
			}
		}
		printf("%d %lld\n",k-1,ans%mod);
	}
	return 0;
}
