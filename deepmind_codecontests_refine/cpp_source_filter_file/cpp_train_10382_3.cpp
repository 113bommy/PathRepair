#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n;
bool ex[N];
struct lll {
  int l, r, c;
};
vector<lll> q[N];
struct dat {
  int x1, y1, x2, y2;
} a[N];
namespace sgt {
const int N = ::N << 2;
set<int> S[N];
int mn[N], mx[N];
void up(int x, int o) {
  if (o)
    mn[x] = mx[x] = 0;
  else
    mn[x] = min(mn[x << 1], mn[x << 1 | 1]),
    mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
  if (!S[x].empty()) {
    auto z = --S[x].end();
    if (!ex[*z])
      mx[x] = max(mx[x], *z);
    else
      mn[x] = max(mn[x], *z);
  }
  if (mn[x] > mx[x]) mx[x] = 0;
}
void ins(int x, int l, int r, int L, int R, int c) {
  if (L <= l && r <= R) {
    if (c > 0) S[x].insert(c);
    if (c < 0) S[x].erase(-c);
    up(x, l == r);
    return;
  }
  if (L <= ((l + r) >> 1)) ins(x << 1, l, ((l + r) >> 1), L, R, c);
  if (R > ((l + r) >> 1)) ins(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R, c);
  up(x, 0);
}
}  // namespace sgt
int main() {
  cin >> n;
  static int X[N], Y[N];
  int tx = 0, ty = 0;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    X[++tx] = x1, X[++tx] = x2;
    Y[++ty] = y1, Y[++ty] = y2;
    a[i] = (dat){x1, y1, x2, y2};
  }
  sort(X + 1, X + tx + 1);
  tx = unique(X + 1, X + tx + 1) - X - 1;
  sort(Y + 1, Y + ty + 1);
  ty = unique(Y + 1, Y + ty + 1) - Y - 1;
  for (int i = 1; i <= n; i++) {
    int lx = lower_bound(X + 1, X + tx + 1, a[i].x1) - X;
    int rx = lower_bound(X + 1, X + tx + 1, a[i].x2) - X;
    a[i].y1 = lower_bound(Y + 1, Y + ty + 1, a[i].y1) - Y;
    a[i].y2 = lower_bound(Y + 1, Y + ty + 1, a[i].y2) - Y;
    q[lx].push_back((lll){a[i].y1, a[i].y2, i});
    q[rx].push_back((lll){a[i].y1, a[i].y2, -i});
  }
  int ans = 0;
  for (int i = 1; i <= tx; i++) {
    for (lll t : q[i]) sgt ::ins(1, 1, ty, t.l, t.r, t.c);
    while (sgt ::mx[1]) {
      int c = sgt ::mx[1];
      ex[c] = 1, ++ans;
      sgt ::ins(1, 1, ty, a[c].y1, a[c].y2, 0);
    }
  }
  cout << ans + 1;
  return 0;
}
