#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 10005
#define ll long long
int a[N],n,pri[N*20],tot,vis[N];ll sum=0;
void get_pri(int x)
{
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0)
		{
			pri[++tot]=i;
			while(x%i==0)x/=i;
		}
	}if(x!=1)pri[++tot]=x;
}
int q_pow(int x,int n,int mod){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)if(!vis[j])for(int j=i+i;j<=n;j+=i)vis[j]=1;
	for(int i=2;i<=n;i++)if(!vis[j])pri[++tot]=j;
	for(int i=n;~i;i--)scanf("%d",&a[i]),get_pri(abs(a[i]));
	sort(pri+1,pri+tot+1);tot=unique(pri,pri+tot+1)-pri-1;
	for(int k=1;k<=tot;k++)if(a[0]%pri[k]==0)
	{
		bool flag=1;int mod=pri[k];
		for(int i=2;i<=20;i++)
		{
			int ret=0,now=i;
			for(int j=1;j<=n;j++)ret=(ret+(ll)now*a[j])%mod,now=(ll)now*i%mod;
			if(ret!=0){flag=0;break;}
		}
		if(flag)printf("%d\n",pri[k]);
	}
}