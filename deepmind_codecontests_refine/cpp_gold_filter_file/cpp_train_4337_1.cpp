#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
long long n;
int k, i, j, t;
int a[101];
long long dp[maxn + 1][101][2];
long long rec(long long p, int i, int t) {
  if (p == 0) return 0;
  if (i > k) return 0;
  if (p <= maxn) {
    if (dp[p][i][t] != -maxn) return dp[p][i][t];
  }
  long long x;
  x = p / a[i];
  if (t == 1) x = -x;
  x = x + rec(p / a[i], i + 1, (t + 1) % 2) + rec(p, i + 1, t);
  if (p <= maxn) dp[p][i][t] = x;
  return x;
}
int main() {
  cin >> n >> k;
  for (i = 0; i <= maxn; i++)
    for (j = 1; j <= k; j++)
      for (t = 0; t <= 1; t++) dp[i][j][t] = -maxn;
  for (i = 1; i <= k; i++) cin >> a[i];
  sort(a + 1, a + k + 1);
  reverse(a + 1, a + k + 1);
  cout << n - rec(n, 1, 0);
  return 0;
}
