#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7; 

int main() {
	ll N; cin >> N;
	bitset<60> bs(N);
	vector<vector<long long>> dp(61, vector<long long>(3, 0));
	dp[60][0] = 1;
	for (int i = 60; i >= 1; --i) {
		if (bs[i - 1]) {
			dp[i - 1][0] = dp[i][0];
			dp[i - 1][1] = dp[i][0] + dp[i][1];
			dp[i - 1][2] = 2 * dp[i][1] + 3 * dp[i][2];
		}
		else {
			dp[i - 1][0] = dp[i][0] + dp[i][1];
			dp[i - 1][1] = dp[i][1];
			dp[i - 1][2] = dp[i][1] + 3 * dp[i][2];
		}
		dp[i - 1][0] %= MOD;
		dp[i - 1][1] %= MOD;
		dp[i - 1][2] %= MOD;
	}
	cout << (((dp[0][0] + dp[0][1]) % MOD) + dp[0][2]) % MOD << endl;
	return 0;
}
