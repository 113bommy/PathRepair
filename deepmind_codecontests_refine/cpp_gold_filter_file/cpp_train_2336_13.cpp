#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 10;
const long long inf = 4e18;
struct S {
  int x, y, z;
  bool operator<(const S &a) const { return y < a.y; }
};
S a[200];
long long dp[(1 << 20) + 10];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int z;
    scanf("%d%d%d", &a[i].x, &a[i].y, &z);
    while (z--) {
      int x;
      scanf("%d", &x);
      a[i].z |= (1 << (x - 1));
    }
  }
  sort(a + 1, a + 1 + n);
  long long ans = inf;
  for (int i = 0; i < (1 << m); i++) dp[i] = inf;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = (1 << m) - 1; j >= 0; j--) {
      dp[j | a[i].z] = min(dp[j | a[i].z], dp[j] + a[i].x);
    }
    ans = min(ans, dp[(1 << m) - 1] + 1ll * a[i].y * k);
  }
  printf("%lld\n", (ans == inf) ? -1ll : ans);
}
