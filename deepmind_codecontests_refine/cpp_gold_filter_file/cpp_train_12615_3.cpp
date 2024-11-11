#include <bits/stdc++.h>
using namespace std;
struct p {
  int a[12];
  int f[4096];
  int ma;
};
p a[2001];
int f[12][4096];
bool cmp(const p& a, const p& b) { return a.ma > b.ma; }
int main() {
  int t;
  int n, m, fk;
  int x, tmp;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[j].a[i]);
        a[j].ma = max(a[j].ma, a[j].a[i]);
      }
    fk = 1 << n;
    sort(a, a + m, cmp);
    m = min(n, m);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < fk; ++j) {
        for (int st = 0; st < n; ++st) {
          tmp = 0;
          for (int k = 0, w = 1; k < n; ++k, w <<= 1) {
            if (j & w) tmp += a[i].a[(k + st) % n];
          }
          a[i].f[j] = max(a[i].f[j], tmp);
        }
      }
    }
    for (int i = 0; i < fk; ++i) f[0][i] = a[0].f[i];
    for (int i = 1; i < m; ++i)
      for (int j = 0; j < fk; ++j)
        for (int k = j; k; k = (k - 1) & j)
          f[i][j] = max(f[i][j], f[i - 1][k] + a[i].f[j ^ k]);
    printf("%d\n", f[m - 1][fk - 1]);
  }
  return 0;
}
