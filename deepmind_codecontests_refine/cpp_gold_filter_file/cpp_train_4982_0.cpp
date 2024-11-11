#include <bits/stdc++.h>
//#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define all(v) v.begin(),v.end()
int n,k,a[5010];
bool dp1[5010][5010],dp2[5010][5010];
signed main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	dp1[0][0]=true;
	rep(i,n-1){
		rep(j,k){
			if(dp1[i][j])dp1[i+1][j]=true;
			if(dp1[i][j]&&j+a[i]<=k)dp1[i+1][j+a[i]]=true;
		}
	}
	dp2[n-1][0]=true;
	for(int i=n-1;i>0;i--){
		rep(j,k){
			if(dp2[i][j])dp2[i-1][j]=true;
			if(dp2[i][j]&&j+a[i]<=k)dp2[i-1][j+a[i]]=true;
		}
	}
	int ans=0;
	rep(i,n){
		vector<int>a1,a2;
		rep(j,k+1){
			if(dp1[i][j])a1.push_back(j);
			if(dp2[i][j])a2.push_back(j);
		}
		bool flag=true;
		for(int x:a1){
			if(upper_bound(all(a2),k-x-1)-lower_bound(all(a2),k-x-a[i]))flag=false;
		}
		if(flag)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
