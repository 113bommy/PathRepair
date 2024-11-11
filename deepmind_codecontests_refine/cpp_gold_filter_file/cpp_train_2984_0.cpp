#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, j, x, y, z;
int ata[(int)(2e5 + 10)], S[(int)(2e5 + 10)], H[(int)(2e5 + 10)],
    A[(int)(2e5 + 10)];
int dp[(int)(2e5 + 10)], ans;
int atabul(int x) {
  if (ata[x] == x) return x;
  return ata[x] = atabul(ata[x]);
}
bool islucky(int x) {
  while (x) {
    if (!(x % 10 == 4 or x % 10 == 7)) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    ata[i] = i;
    S[i] = 1;
  }
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    if (atabul(x) == atabul(y)) continue;
    S[atabul(x)] += S[atabul(y)];
    ata[atabul(y)] = atabul(x);
  }
  for (i = 1; i <= n; i++) {
    if (!H[atabul(i)]) {
      A[S[atabul(i)]]++;
      H[atabul(i)] = 1;
    }
  }
  memset(dp, 5, sizeof dp);
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    if (!A[i]) continue;
    int t = A[i], k = 1;
    while (t) {
      int p = min(k, t);
      t -= p;
      k *= 2;
      p *= i;
      for (j = n; j >= p; j--) dp[j] = min(dp[j - p] + p / i, dp[j]);
    }
  }
  ans = 1000000007;
  for (i = 4; i <= n; i++)
    if (dp[i] <= n and islucky(i)) ans = min(ans, dp[i]);
  if (ans <= n)
    cout << ans - 1 << '\n';
  else
    cout << -1 << '\n';
}
