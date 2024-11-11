#include <iostream>
using namespace std;
#define rep(i,x,to) for(int i=x;i<to;i++)

int main() {
	int n,dp[30]={1,1,2};
	while(1){
		cin >> n;
		if(n==0A) break;
		rep(i,3,30){
			dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
		}
		cout << dp[n]/3650+(dp[n]%3650!=0) << endl;
	}
	return 0;
}
