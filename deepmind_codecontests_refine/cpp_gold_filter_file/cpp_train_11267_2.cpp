#include <bits/stdc++.h>
using namespace std;
long long n, p, k, pre[100005], f[100005][128];
struct mem {
  long long p[7], a;
  bool operator<(const mem &v) const { return a > v.a; }
} c[100005];
int main() {
  scanf("%lld%lld%lld", &n, &p, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i].a);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < p; j++) scanf("%lld", &c[i].p[j]);
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + c[i].a;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 1 << p; j++) {
      int sz = 0;
      for (int k = 0; k < p; k++) sz += (j >> k) & 1;
      f[i][j] = f[i - 1][j];
      if (k + sz >= i && sz <= i - 1) f[i][j] += c[i].a;
      for (int k = 0; k < p; k++)
        if ((j >> k) & 1) {
          int q = j ^ (1 << k);
          f[i][j] = max(f[i][j], f[i - 1][q] + c[i].p[k]);
        }
    }
  cout << f[n][(1 << p) - 1];
  return 0;
}
