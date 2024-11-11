#include <bits/stdc++.h>
using namespace std;
const int N = 400000 + 7;
int l, m, n;
struct sta {
  int x, p;
} v[N];
struct str {
  int x, i, p;
} e[N];
int w[N];
struct sec {
  int l, r, p;
} a[N];
int cov[N << 2], sub[N << 2];
long long ans;
void cover(int p, int l, int r, int x, int y, int z) {
  if (cov[p]) return;
  if (x <= l && r <= y && !sub[p])
    cov[p] = sub[p] = 1, ans += 1ll * z * (w[r] - w[l - 1]);
  else {
    int mid = l + r >> 1;
    if (x <= mid) cover(p << 1, l, mid, x, y, z);
    if (y > mid) cover(p << 1 | 1, mid + 1, r, x, y, z);
    cov[p] = cov[p << 1] & cov[p << 1 | 1];
    sub[p] = sub[p << 1] | sub[p << 1 | 1];
  }
}
int main() {
  scanf("%d%d%d", &l, &m, &n);
  ++n;
  for (int i = 2; i <= n; ++i) scanf("%d%d", &v[i].x, &v[i].p);
  sort(v + 1, v + n + 1, [](sta a, sta b) { return a.x < b.x; });
  for (int i = 2; i <= n; ++i)
    if (v[i].x - v[i - 1].x > m) return printf("-1"), 0;
  if (l - v[n].x > m) return printf("-1"), 0;
  e[1] = (str){1, 1, 0};
  e[n + 1] = (str){m + 1, n + 1, 0};
  for (int i = 2; i <= n; ++i)
    e[i] = (str){v[i].x + 1, i, 0},
    e[n + i] = (str){min(v[i].x + m, l) + 1, n + i, 0};
  sort(e + 1, e + n * 2 + 1, [](str a, str b) { return a.x < b.x; });
  w[e[1].p = 1] = e[1].x;
  for (int i = 2; i <= n * 2; ++i)
    e[i].p = e[i - 1].p + (e[i].x != e[i - 1].x), w[e[i].p] = e[i].x;
  sort(e + 1, e + n * 2 + 1, [](str a, str b) { return a.i < b.i; });
  for (int i = 1; i <= n; ++i) a[i] = (sec){e[i].p, e[n + i].p, v[i].p};
  sort(a + 1, a + n + 1, [](sec a, sec b) { return a.p < b.p; });
  for (int i = 1; i <= n; ++i)
    cover(1, 1, e[n * 2].p, a[i].l + 1, a[i].r, a[i].p);
  printf("%lld", ans);
  return 0;
}
