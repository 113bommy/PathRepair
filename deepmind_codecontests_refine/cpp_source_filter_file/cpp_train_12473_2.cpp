#include <bits/stdc++.h>
using namespace std;
int n;
long long` a[100009];
long long dp[100009];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[2]=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		dp[i]=min(abs(a[i-1]-a[i])+dp[i-1],abs(a[i-2]-a[i])+dp[i-2]);
	}
	cout<<dp[n]<<endl;
}
