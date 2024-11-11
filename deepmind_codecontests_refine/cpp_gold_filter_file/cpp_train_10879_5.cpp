#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1000005;
const int MAX = 151;
const long long MOD = 1000000007LL;
const int MOD1 = 100000007;
const int MOD2 = 100000009;
const int INF = 500000000;
const double EPS = 0.000000001;
int read() {
  int x = 0, f = 1;
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
int a[N], b[N];
long long dp[2][N];
int main() {
  int i, j, k, n, cnt;
  long long L;
  scanf("%d%I64d%d", &n, &L, &k);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) b[i] = a[i];
  sort(b, b + n);
  cnt = unique(b, b + n) - b;
  for (i = 0; i < n; i++) a[i] = lower_bound(b, b + cnt, a[i]) - b;
  int la = 0, now = 1;
  long long seg = L / n, ans = 0;
  memset(dp, 0, sizeof(dp));
  dp[now][0] = 1LL;
  for (i = 1; i <= k && i <= seg + 1; i++) {
    la = now;
    now = 1 - now;
    for (j = 0; j < cnt; j++) dp[now][j] = 0;
    for (j = 1; j < cnt; j++) dp[la][j] = (dp[la][j] + dp[la][j - 1]) % MOD;
    for (j = 0; j < n; j++)
      dp[now][a[j]] = (dp[now][a[j]] + dp[la][a[j]]) % MOD;
    for (j = 0; j < cnt; j++)
      ans = (ans + (seg - i + 1) % MOD * dp[now][j] % MOD) % MOD;
    for (j = 0; j < L - seg * n; j++) ans = (ans + dp[la][a[j]]) % MOD;
  }
  printf("%I64d\n", ans);
  return 0;
}
