#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,t,e,x,ab,a[200005],dp[200005];
int main(){
	n=read(),e=read(),t=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[n+1]=e;
	for(int i=1;i<=n;i++){
		while((a[i]-a[ab+1])*2>t)
			x=min(x,dp[ab]-2*a[ab+1]),ab++;
		dp[i]=min((ll)(1e18),dp[ab]+t);
		if(ab)dp[i]=min(dp[i],2*a[i]+x);
	}
	printf("%lld",dp[n]+e);
	return 0;
}  
