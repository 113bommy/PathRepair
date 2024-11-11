#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * y;
}
const int N = 3000;
const int M = 1e6;
int a, b;
long long s[N + 10][N + 10], sum[N + 10], ans;
vector<long long> dp;
inline void dq(int l, int r) {
  if (l == r) {
    long long tmp = 0;
    for (int i = 0; i <= min(1ll * b, s[l][0]); i++) {
      ans = max(ans, dp[b - i] + tmp);
      tmp += s[l][i + 1];
    }
    return;
  }
  vector<long long> tmp = dp;
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; i++) {
    for (int k = b; k >= s[i][0]; k--)
      dp[k] = max(dp[k], dp[k - s[i][0]] + sum[i]);
  }
  dq(mid + 1, r);
  dp = tmp;
  for (int i = mid + 1; i <= r; i++) {
    for (int k = b; k >= s[i][0]; k--)
      dp[k] = max(dp[k], dp[k - s[i][0]] + sum[i]);
  }
  dq(l, mid);
}
signed main() {
  a = read();
  b = read();
  for (int i = 1; i <= a; i++) {
    s[i][0] = read();
    for (int j = 1; j <= s[i][0]; j++) s[i][j] = read(), sum[i] += s[i][j];
  }
  dp.resize(b + 1);
  dq(1, a);
  printf("%lld", ans);
  return 0;
}
