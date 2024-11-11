#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double eps = 1e-8;
const int nm = 100005;
int n, k, t;
long long m;
long long a[nm];
int main() {
  int i, j, x, y, z, w;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d.%d.%d.%d", &x, &y, &z, &w);
    a[i] = (((1ll * x) << 24) + ((1ll * y) << 16) + ((1ll * z) << 8) + w);
  }
  for (i = 31; i > 0; i--) {
    m = m + ((1ll) << i);
    set<long long> s;
    for (j = 1; j <= n; j++) s.insert(m & a[j]);
    if (s.size() == k) break;
  }
  if (i == 0)
    cout << -1;
  else {
    printf("%I64d.%I64d.%I64d.%I64d", m >> 24 & 255, (m >> 16) & 255,
           (m >> 8) & 255, m & 255);
  }
  return 0;
}
