#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 20];
const long long inf = 4000000000LL * 1000000000LL;
struct triple {
  long long a, b, c;
  triple() {}
  triple(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator<(const triple& B) const { return b < B.b; }
};
triple T[100];
int main() {
  int n, m;
  long long b;
  scanf("%d%d%lld", &n, &m, &b);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%lld%lld%d", &T[i].a, &T[i].b, &k);
    while (k--) {
      int a;
      scanf("%d", &a);
      T[i].c += (1 << (a - 1));
    }
  }
  long long ans = inf;
  for (int i = 1; i < (1 << m); i++) dp[i] = inf;
  sort(T, T + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++)
      dp[j | T[i].c] = min(dp[j | T[i].c], dp[j] + T[i].a);
    ans = min(ans, dp[(1 << m) - 1] + T[i].b * b);
  }
  printf("%lld\n", ans >= inf ? -1LL : ans);
  return 0;
}
