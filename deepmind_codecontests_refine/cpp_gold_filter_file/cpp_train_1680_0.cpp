#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  long long a, b, k;
  void scan() { scanf("%lld%lld%lld", &a, &b, &k); }
  bool operator<(const node &other) const { return b > other.b; }
} a[510];
long long dp[510];
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) a[i].scan();
    sort(a + 1, a + 1 + n);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
      for (int j = n; j >= 0; --j) {
        dp[j + 1] = max(dp[j + 1], dp[j] + a[i].a - a[i].b * j);
        dp[j] = max(dp[j], dp[j] + a[i].a - a[i].b * a[i].k);
      }
    }
    printf("%lld\n", *max_element(dp, dp + 1 + n));
  }
  return 0;
}
