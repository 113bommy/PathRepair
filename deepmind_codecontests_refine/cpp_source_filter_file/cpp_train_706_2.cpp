#include <bits/stdc++.h>

using namespace std;

const int MAXK = 1e5 + 10;
const int MOD = 1e9 + 7;

int pref[MAXK],dp[MAXK],N,K;

int main(){
	cin >> N >> K;
	dp[0] = 1;
	for(int kid = 1;kid<=N;kid++){
		int c;
		cin >> c;
		pref[0] = dp[0];
		dp[0] = 0;
		for(int i = 1;i<=K;i++){
			pref[i] = (pref[i-1] + dp[i]) % MOD;
		}
		for(int i = 0;i<=K;i++){
			dp[i] = (pref[i] - (i-c>=0 ? pref[i-c-1] : 0);
		}
	}

	int ans = dp[K];
	if(ans < 0) ans += MOD; 
	printf("%d\n",ans);

	return 0;
}
