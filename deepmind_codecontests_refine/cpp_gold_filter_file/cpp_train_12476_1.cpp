#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int mod=998244353;
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=ret*x%md;x=x*x%md;}while(y>>=1);return ret;}
int n,m;
int fact[1000005],inv[1000005];
int C(int nn,int mm){
	return fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
signed main(){
	cin>>n>>m;
	fact[0]=1;
	for(int i=1;i<=1e6;i++)fact[i]=fact[i-1]*i%mod;
	inv[1000000]=modpow(fact[1000000],mod-2);
	for(int i=1e6-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	if(n>m)swap(n,m); 
	const int inv2=modpow(2,mod-2);
	int result=C(n+m,n)*m%mod;
	for(int i=1;i<=n;i++){
		int ways=C(i+i,i)*C(n-i+m-i,n-i)%mod;
		result+=ways*inv2%mod;
		result%=mod;
	}
	cout<<result*modpow(C(n+m,n),mod-2)%mod<<endl;
	return 0;
}