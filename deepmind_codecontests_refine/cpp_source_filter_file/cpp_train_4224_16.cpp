#include <bits/stdc++.h>
template <typename T>
inline bool mini(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
using namespace std;
const int N = 10005;
long long s[N], p[N], dp[2][N], m;
int n;
int main() {
  while (scanf("%d %lld", &n, &m) == 2) {
    for (int i = 0; i < n; i++) scanf("%lld", p + i);
    for (int i = 0; i < n; i++) scanf("%lld", s + i);
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
      int cur = i & 1;
      for (int j = 0; j < i; j++) dp[cur][j] = dp[!cur][j] + p[i - 1] + j * m;
      dp[cur][i] = 1LL << 40;
      for (int j = 1; j < i + 1; j++)
        mini(dp[cur][j], dp[!cur][j - 1] + s[i - 1]);
    }
    long long ans = 1LL << 40;
    for (int j = 0; j < n + 1; j++) mini(ans, dp[n & 1][j]);
    printf("%lld\n", ans);
  }
  return 0;
}
