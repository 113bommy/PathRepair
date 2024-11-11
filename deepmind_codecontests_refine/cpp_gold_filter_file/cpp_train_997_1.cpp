#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17L;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int Mod = 1e9 + 7;
struct Souvenirs {
  int w, c;
  bool friend operator<(Souvenirs x, Souvenirs y) {
    return ((double)x.c / x.w) > ((double)y.c / y.w);
  }
} a[maxn];
int n, m;
long long dp[3 * maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].w, &a[i].c);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) dp[i] = -INF;
  dp[0] = 0;
  int up = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    up += a[i].w;
    if (up > m) up = m;
    int least = max(a[i].w, up - 6);
    for (int j = up; j >= least; j--) {
      dp[j] = max(dp[j], dp[j - a[i].w] + a[i].c);
      ans = max(ans, dp[j]);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
