#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
struct node {
  int w, v, id;
  bool operator<(const node& p) const {
    if (w != p.w)
      return w < p.w;
    else
      return v < p.v;
  }
} a[maxn];
int n, k, h;
int use[maxn];
bool check(long double t) {
  int now = k;
  for (int i = n; i; --i) {
    if (t * a[i].v / h >= now) {
      use[now] = a[i].id;
      --now;
    }
    if (now == 0) return true;
  }
  return false;
}
int ans[maxn];
int main() {
  scanf("%d%d%d", &n, &k, &h);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].w), a[i].id = i;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].v);
  sort(a + 1, a + 1 + n);
  long double l = 0, r = 1e10;
  for (int i = 1; i <= 200; ++i) {
    long double mid = (r + l) / 2;
    if (check(mid)) {
      r = mid;
      for (int i = 1; i <= k; ++i) ans[i] = use[i];
    } else
      l = mid;
  }
  for (int i = 1; i <= k; ++i) printf("%d ", ans[i]);
  return 0;
}
