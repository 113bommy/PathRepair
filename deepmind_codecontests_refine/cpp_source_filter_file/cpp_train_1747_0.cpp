#include<bits/stdc++.h>
#define ll long long
#define ljc 1000000007
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
ll n,A,fac[10000001],inv[10000001],_inv[10000001];
inline ll getC(ll n,ll m){
    if (n<m) return 0;
    return fac[n]*_inv[m]%ljc*_inv[n-m]%ljc;
}
inline ll query(ll i1,ll i2){
	if (i1<=0||i2<=0||i1>i2) return 0;
	return fac[i2]*_inv[i1-1]%ljc;
}
inline solve(ll i1,ll i2){
	if (n-A<i1) return 0; 
	return query(n-A-i1+1,n-A)*query(i1+i2,i2-n-A+1)%ljc*query(n-A+i1+i2+2,n)%ljc;
}
ll dp[5001][5001],sum[5001][5001];
inline void add(ll &a,ll b){a+=b;a%=ljc;}
signed main(){
    fac[0]=inv[0]=inv[1]=_inv[0]=1;
    for (ll i=1;i<=10000000;i++) fac[i]=fac[i-1]*i%ljc;
    for (ll i=2;i<=10000000;i++) inv[i]=(ljc-inv[ljc%i]*(ljc/i)%ljc)%ljc;
    for (ll i=1;i<=10000000;i++) _inv[i]=_inv[i-1]*inv[i]%ljc;
    n=read(),A=read(); 
//    for (int i1=0;i1<=A;i1++){
//    	for (int i2=0;i2+i1<=A;i2++){
//    		if (i1==0&&i2==0){
//    			dp[0][0]=1;continue;
//			}
//    		if (i2) add(dp[i1][i2],dp[i1][i2-1]);
//    		for (int j=1;j<i1;j++) add(dp[i1][i2],dp[i1-j-1][i2]*getC(i1+i2-1,j)%ljc);
//		}
//	}
//	ll _=0;
//	for (int i=2;i<=A+1;i++){
//		for (int i1=0;i1<i;i1++){
//			_=(_+solve(i1,i-1-i1)*dp[i1][i-1-i1]%ljc)%ljc;				
//		}
//	}
	ll _=0;
	for (int T=2;T<=A+1;T++) {
		int x=T-1,y=max(A-T,0ll),z=n-A;
		for (int i=0;i<T;i++){
			if (i&1) add(_,ljc-getC(x,i)*(x-i)%ljc*inv[x-i+z]%ljc*fac[x-i+y+z]%ljc);
			else add(_,getC(x,i)*(ll)(x-i)%ljc*inv[x-i+z]%ljc*fac[x-i+y+z]%ljc);
		} 
	}
	cout<<_;
}