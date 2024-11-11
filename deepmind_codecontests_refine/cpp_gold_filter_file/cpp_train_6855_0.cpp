#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1,c=getchar();
	while(c<48) c=='-'&&(f=-1),c=getchar();
	while(c>47) x=x*10+c-'0',c=getchar();
	return x*f;
}

const int MAXN = 5005;
const int mod = 1e9+7;
int f[MAXN][MAXN];
int n,m;

inline int dp(int x,int y,int ret=0)
{
	memset(f,0,sizeof(f));
	for(int i=0;i<=x;++i) f[0][i]=1;
	for(int i=1;i<=y;++i)
		for(int j=0;j<=x;++j)
		{
			if(j<x) (f[i][j]+=f[i-1][j+1])%=mod,(f[i][j]+=f[i-1][j])%=mod;
			if(j) (f[i][j]+=f[i-1][j])%=mod,(f[i][j]+=f[i-1][j-1])%=mod;
		}
	for(int i=0;i<=x;++i) (ret+=f[y][i])%=mod;
	return ret;
}

int main(int argc, char const *argv[])
{
	n=read(); m=read();
	printf("%d\n", (dp(n,m)-dp(n-1,m)+mod)%mod);
	return 0;
}

