#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,k,m,t,ans,mod=998244353,a[305],b[305],dp[305][305][305];
char s[305];
int main(){
	scanf("%s%d",s+1,&k);
	ans=strlen(s)/100;
	for(int i=1;s[i];i++)
		m+=s[i]=='1';
	for(int i=1;s[i];i++)
		if(s[i]=='0')
			a[++n]=t,t=0;
		else t++;
	a[++n]=t;
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	k=min(k,m);
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=b[i];j<=b[n];j++)
			for(int h=0;h<=k;h++){
				if(!dp[i][j][h])continue;
				for(int f=max((ll)j,b[i+1]);f<=b[n];f++)
					if(h+f-j-a[i+1]<=k){
						if(i+1==n and f-j>a[i+1])
							break;
						int z=f-j<=a[i+1]?0:f-j-a[i+1];
						dp[i+1][f][h+z]=(dp[i+1][f][h+z]+dp[i][j][h])%mod;
					}
			}
	for(int i=0;i<=k;i++)
		ans=(ans+dp[n][m][i])%mod;
	printf("%lld",ans);
	return 0;
}