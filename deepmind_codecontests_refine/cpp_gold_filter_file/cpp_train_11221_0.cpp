#include <bits/stdc++.h>
#define ll long long
using namespace std;
int h,n,a[1001],b[1001],dp[10001],ans=1e9;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>h>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=h;i++) dp[i]=1e9;
	for(int i=0;i<=h;i++)
		for(int j=1;j<=n;j++){
			if(i+a[j]>=h){ ans=min(ans,dp[i]+b[j]); continue; }
			dp[i+a[j]]=min(dp[i+a[j]],dp[i]+b[j]);
		}
	cout<<ans;
}