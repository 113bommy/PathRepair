#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 100010;
const double eps = 1e-10;
const double eps2 = 1e-16;
int mi[maxn] = {};
int vi[maxn] = {};
int n, k, h;
struct item {
  int m, ind, num;
  item() {}
  item(int m, int ind, int num) : m(m), ind(ind), num(num) {}
  bool operator<(const item &oth) const {
    return m < oth.m || (m == oth.m && num < oth.num);
  }
};
item a[maxn] = {};
int res[maxn] = {};
int KK;
bool can(double t) {
  for (int i = 0; i < n; ++i) {
    a[i].m = mi[i];
    a[i].ind = i;
    double ttt = vi[i] * t / h + 0.1;
    if (ttt > k)
      a[i].num = k;
    else
      a[i].num = (int)(ttt);
  }
  sort(a, a + n);
  reverse(a, a + n);
  int need = k;
  int lstm = INF;
  KK = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].num < need) continue;
    if (a[i].m <= lstm) {
      res[KK++] = a[i].ind;
      need--;
      if (need == 0) return true;
      lstm = a[i].m;
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &k, &h);
  for (int i = 0; i < n; ++i) scanf("%d", &mi[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &vi[i]);
  double r = 1e10;
  double l = 0;
  for (int it = 0; it < 100; ++it) {
    double m = (l + r) / 2.0;
    if (can(m))
      r = m;
    else
      l = m;
  }
  can(r);
  for (int i = KK - 1; i >= 0; --i) printf("%d ", res[i] + 1);
  return 0;
}
