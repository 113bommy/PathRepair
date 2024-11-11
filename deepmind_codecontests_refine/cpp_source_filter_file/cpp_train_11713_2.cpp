#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
double dp[200005], f[200005];
int a[200005];
int main() {
  int T, i, j, k, n, m;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    puts("1");
    return 0;
  }
  int s = 0;
  dp[0] = m - 1;
  for (i = 0; i < n; i++) {
    s += a[i];
    double p = 1. / (m - 1.);
    f[0] = dp[0];
    for (j = 1; j <= (i + 1) * m; j++) f[j] = f[j - 1] + dp[j];
    for (j = (i + 1) * m; j > 0; j--) {
      dp[j] = f[j - 1];
      if (j >= a[i]) dp[j] -= dp[j - a[i]];
      if (j >= m + 1) dp[j] -= f[j - m - 1];
      dp[j] *= p;
    }
    dp[0] = 0;
  }
  double ans = 0;
  for (i = 1; i < s; i++) ans += dp[i];
  printf("%.9lf\n", ans + 1);
  return 0;
}
