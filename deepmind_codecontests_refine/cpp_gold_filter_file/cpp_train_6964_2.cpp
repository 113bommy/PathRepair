#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, T, S;
	cin >> N >> T >> S;

	vector<int> A(N);
	vector<int> B(N);
	vector<int> dp(T+1, 0);

	for (int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}

	int ans = 0;
	for (int n = 0; n <N; n++){
		for (int t = T-B[n]; t >= 0; t--){
			if (t < S && S < t+B[n]) continue;
			dp[t+B[n]] = max(dp[t]+A[n], dp[t+B[n]]);
			ans = max(ans, dp[t+B[n]]);
		}
	}

	cout << ans << endl;
	return 0;
}