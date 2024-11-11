#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 998244353;
const int MAXN = 600005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int tag[MAXN << 2], mx[MAXN << 2], b[MAXN << 1];
struct anode {
  int x, l, r, c;
} a[MAXN << 1];
void up(int x) { mx[x] = max(mx[x << 1], mx[x << 1 | 1]); }
void down(int x) {
  if (tag[x] == 0) return;
  tag[x << 1] += tag[x], tag[x << 1 | 1] += tag[x];
  mx[x << 1] += tag[x], mx[x << 1 | 1] += tag[x];
  tag[x] = 0;
}
void update(int x, int l, int r, int L, int R, int c) {
  if (l >= L && r <= R) {
    tag[x] += c, mx[x] += c;
    return;
  }
  down(x);
  int mid = (l + r) >> 1;
  if (R <= mid)
    update(x << 1, l, mid, L, R, c);
  else if (L > mid)
    update(x << 1 | 1, mid + 1, r, L, R, c);
  else
    update(x << 1, l, mid, L, mid, c),
        update(x << 1 | 1, mid + 1, r, mid + 1, R, c);
  up(x);
}
signed main() {
  int n = read(), r = read() * 2;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read(), _x = x + y, _y = y - x;
    a[i * 2 - 1] = (anode){_x, _y, _y + r, 1},
              a[i * 2] = (anode){_x + r, _y, _y + r, -1};
    b[i * 2 - 1] = _y, b[i * 2] = _y + r;
  }
  sort(b + 1, b + n * 2 + 1);
  int m = unique(b + 1, b + n * 2 + 1) - b;
  sort(a + 1, a + n * 2 + 1, [&](anode a, anode b) {
    return (a.x < b.x) || (a.x == b.x && a.c > b.c);
  });
  int ans = 0;
  for (int i = 1; i <= n * 2; i++) {
    a[i].l = lower_bound(b + 1, b + m + 1, a[i].l) - b,
    a[i].r = lower_bound(b + 1, b + m + 1, a[i].r) - b;
    update(1, 1, m, a[i].l, a[i].r, a[i].c);
    upmax(ans, mx[1]);
  }
  printf("%d\n", ans);
  return 0;
}
