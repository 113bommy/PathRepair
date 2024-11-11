#include <bits/stdc++.h>
using namespace std;
int n;
int h[200005];
long long a[200005];
long long bit[200005],dp[200005];
inline void modify(int p,long long v){
	for(int i=p+1;i<=200003;i+=(i&-i){
		bit[i]=max(bit[i],v);
	}
}
inline long long query(int p){
	long long res=0;
	for(int i=p;i;i-=(i&-i){
		res=max(res,bit[i]);
	}
	return res;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>h[i];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=200003;++i){
		bit[i]=-2e15;
		dp[i]=-2e15;
	}
	modify(0,0);
	dp[0]=0;
	for(int i=1;i<=n;++i){
		dp[h[i]]=max(dp[h[i]],query(h[i])+a[i]);
		modify(h[i],dp[h[i]]);
	}
	cout<<query(n+1)<<'\n';
	return 0;
}