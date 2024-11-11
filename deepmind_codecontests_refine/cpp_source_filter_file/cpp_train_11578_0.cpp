#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long __64inf = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 1e6 + 50;
const int mod = 1e9 + 7;
struct node {
  int l, r, d;
  node(int l = 0, int r = 0, int d = 0) : l(l), r(r), d(d) {}
} T[MAX];
int a[MAX];
int m, n, k, t;
bool check(int mid) {
  int need = 0, last = 0;
  for (int i = 1; i <= n; i++) {
    if (T[i].d <= mid) continue;
    if (T[i].l > last) {
      last = T[i].r;
      need += T[i].r - T[i].l + 1;
    } else {
      need += max(0, T[i].r - last);
      last = max(last, T[i].r);
    }
  }
  need *= 2;
  need += n + 1;
  return need <= t;
}
int main() {
  scanf("%d%d%d%d", &m, &n, &k, &t);
  for (int i = 1; i <= m; i++) scanf("%d", a + i);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d", &T[i].l, &T[i].r, &T[i].d);
  }
  sort(T + 1, T + 1 + n,
       [](const node& a, const node& b) { return a.l < b.l; });
  sort(a + 1, a + 1 + m, [](int x, int y) { return x < y; });
  int l = -1, r = a[m];
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%d\n", a + m + 1 - lower_bound(a + 1, a + 1 + m, r));
  return 0;
}
