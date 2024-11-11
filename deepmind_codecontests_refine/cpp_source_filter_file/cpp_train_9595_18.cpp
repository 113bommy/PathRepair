#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int mod = 998244353;
int sum(int a, int b) {
  int s = (a + b);
  if (s >= mod) s -= mod;
  return s;
}
int sub(int a, int b) {
  int s = a - b;
  if (s < 0) s += mod;
  return s;
}
int mult(int a, int b) { return (1LL * a * b) % mod; }
int dp[1010][1010], pref[1010][1010], le[1010], a[1010];
int n, k, ans = 0;
long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int solve(int x) {
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  le[0] = 0;
  for (int i = 1; i <= n; i++) {
    le[i] = le[i - 1];
    while (a[i] - a[le[i] + 1] >= x) le[i]++;
  }
  dp[0][0] = 1;
  for (int i = 0; i <= k - 1; i++) {
    pref[i][0] = dp[i][0];
    for (int j = 1; j <= n; j++) pref[i][j] = sum(pref[i][j - 1], dp[i][j]);
    for (int j = 1; j <= n; j++) dp[i + 1][j] = pref[i][le[j]];
  }
  int ans = 0;
  for (int j = 1; j <= n; j++) ans = sum(ans, dp[k][j]);
  return ans;
}
int main() {
  n = rd();
  k = rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  sort(a + 1, a + 1 + n);
  for (int x = 1; (k - 1) * x <= 101010; x++) ans = sum(ans, solve(x));
  printf("%lld\n", ans);
}
