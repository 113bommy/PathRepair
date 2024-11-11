#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n>>K;
	vector<vector<int> > pr(10, vector<int>(n+1,0));
	vector<int> ko(10, 0);
	for (int i = 0; i < n; i++) {
		int c, g; cin >> c >> g;
		g--;
		pr[g][ko[g]] = c;
		ko[g]++;
	}
	for (int i = 0; i < 10; i++) {
		sort(pr[i].begin(), pr[i].end());
		reverse(pr[i].begin(), pr[i].end());
	}
	vector<vector<int> > sum(10,vector<int> (n+1,0));
	for (int i = 0; i < n; i++) {
		int su = 0;
		for (int j = 1; j <= ko[i]; j++) {
			su += pr[i][j-1];
			sum[i][j] = su + j * (j - 1);
		}
	}
	vector<vector<int> > dp(10, vector<int>(n + 1, 0));
	dp[0] = sum[0];
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= k; j++) {
			for (int kk = j; kk <= k; kk++) {
				dp[i][kk] = max(dp[i][kk], dp[i - 1][j] + sum[i][kk - j]);
			}
		}
	}
	cout << dp[9][k] << endl;
	return 0;
}
