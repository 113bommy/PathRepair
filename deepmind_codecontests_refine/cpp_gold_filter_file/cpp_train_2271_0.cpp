#include<bits/stdc++.h>
using namespace std;
struct inp{
	int w,s;
	long long v;
	inline bool operator <(const inp &a) const{
		return min(s-a.w,a.s)>min(a.s-w,s);
	}
}a[1005];
long long dp[1005][10005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d %lld",&a[i].w,&a[i].s,&a[i].v);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=-1e18;
		}
	}
	long long ma=0;
	dp[0][a[0].s]=a[0].v;
	ma=max(a[0].v,ma);
	for(int i=1;i<n;i++){
		for(int j=0;j<=10000;j++) dp[i][j]=dp[i-1][j];
		dp[i][a[i].s]=max(dp[i][a[i].s],a[i].v);
		for(int j=a[i].w;j<=10000;j++){
			dp[i][min(a[i].s,j-a[i].w)]=max(dp[i][min(a[i].s,j-a[i].w)],dp[i-1][j]+a[i].v);
		}
		for(int j=0;j<=10000;j++) ma=max(ma,dp[i][j]);
	}
	cout<<ma;
}