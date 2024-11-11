#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[200010];
int dp[200010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int b=a[i];
		dp[b]=dp[b-1]+1;
		if(ans<dp[b]){
			ans=dp[b];
		}
	}
		
	cout<<n-ans<<endl;
	
}