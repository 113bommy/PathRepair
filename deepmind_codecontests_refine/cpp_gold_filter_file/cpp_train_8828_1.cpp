#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, ans;
vector<int> V[100100];
int dp[100100];

int f(int a) {
	if (V[a].size() == 0) return 0;
	if (dp[a] != -1) return dp[a];
	dp[a] = 0;
	for(int i=0; i<V[a].size(); i++) {
		int b = V[a][i];
		dp[a] = max(dp[a], f(b)+1);
	}
	return dp[a];
}

int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		cin >> a >> b;
		V[a].push_back(b);
	}
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=N; i++) {
		ans = max(ans, f(i));
	}
	cout << ans << endl;
	return 0;
}