#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline ll read()
{
	ll x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MOD 1000000007
ll s[MN+5];
int l[MN+5],f[MN+5][2],S[MN+5];
inline int mod(int x){return x<MOD?x:x-MOD;}
int main()
{
	int n,i,x;ll a,b;
	n=read();a=read();b=read();if(a>b)swap(a,b);
	for(i=1;i<=n;++i)s[i]=read();s[0]=-1e18;s[++n]=2e18;
	for(l[1]=i=1;++i<n;)l[i]=s[i]-s[i-1]<a?i:l[i-1];
	for(f[0][1]=S[0]=i=1;i<=n;++i)
	{
		if(s[i]-s[i-1]>=b)f[i][1]=mod(f[i-1][0]+f[i-1][1]);
		if(i>1)
		{
			x=min(i-2,(int)(upper_bound(s,s+n+1,s[i]-b)-s-1));
			if(l[i-1]-1<=x)f[i][0]=mod(S[x]+MOD-(l[i-1]-1>0?S[l[i-1]-2]:0));
		}
		S[i]=mod(S[i-1]+mod((s[i+1]-s[i-1]>=a?f[i][0]:0)+f[i][1]));
	}
	printf("%d",mod(f[n][0]+f[n][1]));
}