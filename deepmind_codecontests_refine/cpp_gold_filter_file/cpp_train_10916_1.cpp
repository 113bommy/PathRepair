#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int n, m, k;
int a[110000];
long long dp[110000][310];
int q[110000], h[110000], xx[110000][310];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++)
		dp[0][i] = -1e18;
	for (int i = 0; i <= k; i++)
		q[i] = h[i] = 1, xx[i][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			while (q[j] <= h[j] && xx[j][q[j]] < i - m)
				q[j] += 1;
			dp[i][j + 1] = dp[xx[j][q[j]]][j] + 1LL * (j + 1) * a[i];
		}
		for (int j = 0; j <= k; j++) {
			while (q[j] <= h[j] && dp[xx[j][h[j]]][j] <= dp[i][j])
				h[j] -= 1;
			xx[j][++h[j]] = i;
				// q[j] += 1;
		}
	}
	long long ans = -1e18;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i][k]);
	cout << ans << endl;
}