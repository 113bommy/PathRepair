#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 10;
struct re {
  long long a, b;
  re(long long k1 = 0, long long k2 = 0) : a(k1), b(k2) {}
  bool operator<(const re &it) const { return a > it.a; }
};
re flower[MAXN];
long long presum[MAXN];
int main() {
  int cas, n, m;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%lld %lld", &flower[i].a, &flower[i].b);
    }
    sort(flower + 1, flower + 1 + m);
    presum[0] = 0;
    for (int i = 1; i <= m; ++i) {
      presum[i] = presum[i - 1] + flower[i].a;
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i) {
      int xu = upper_bound(flower + 1, flower + 1 + m, re(flower[i].b, 0)) -
               flower - 1;
      long long now;
      if (xu >= n) {
        now = presum[n];
        ;
      } else if (xu < i) {
        now = presum[xu] + flower[i].a + (n - 1 - xu) * flower[i].b;
      } else if (xu > i) {
        now = presum[xu] + (n - xu) * flower[i].b;
      }
      ans = max(now, ans);
    }
    printf("%lld\n", ans);
  }
}
