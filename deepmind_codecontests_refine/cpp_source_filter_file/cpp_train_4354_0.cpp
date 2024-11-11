a#include <bits/stdc++.h>
using namespace std;

const int mxN=3000;
int n, a[mxN];
long long dp[mxN][mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=n-1; i>=0; --i) {
		for(int j=i+1; j<=n; ++j) {
			dp[i][j]=max(a[i]-dp[i+1][j], a[j-1]-dp[i][j-1]);
		}
	}
	cout << dp[0][n];
}