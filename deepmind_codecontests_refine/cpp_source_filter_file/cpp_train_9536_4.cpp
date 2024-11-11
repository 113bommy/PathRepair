#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node {
  int x, y;
};
vector<node> v[N];
long long s[N << 2];
int mn[N << 2], tg[N << 2], len[N << 2], a[N], b[N], c[N];
void build(int k, int l, int r) {
  len[k] = r - l + 1;
  if (l == r) return;
  int mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void add(int k, int vl) {
  mn[k] = tg[k] = vl;
  s[k] = 1ll * len[k] * vl;
}
void push_d(int k) {
  if (tg[k] == 0) return;
  add(k << 1, tg[k]);
  add(k << 1 | 1, tg[k]);
  tg[k] = 0;
}
void push_up(int k) {
  s[k] = s[k << 1] + s[k << 1 | 1];
  mn[k] = min(mn[k << 1], mn[k << 1 | 1]);
}
int query(int k, int l, int r, int vl) {
  if (mn[k] >= vl) return r + 1;
  if (l == r) return l;
  int mid = l + r >> 1, tp;
  push_d(k);
  if (mn[k << 1] < vl)
    tp = query(k << 1, l, mid, vl);
  else
    tp = query(k << 1 | 1, mid + 1, r, vl);
  push_up(k);
  return tp;
}
void modify(int k, int l, int r, int x, int y, int vl) {
  if (x <= l && r <= y) return add(k, vl);
  int mid = l + r >> 1;
  push_d(k);
  if (x <= mid) modify(k << 1, l, mid, x, y, vl);
  if (mid < y) modify(k << 1 | 1, mid + 1, r, x, y, vl);
  push_up(k);
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  for (register int i = (1); i <= (n); ++i) {
    cin >> a[i] >> b[i] >> c[i];
    v[p].push_back((node){b[i], c[i]});
    v[a[i]].push_back((node){p, c[i]});
    v[a[i]].push_back((node){b[i], r});
  }
  long long ans = 0;
  int l, x, y, pt;
  build(1, 1, q);
  for (register int i = (p); i >= (1); --i) {
    l = v[i].size();
    for (register int j = (0); j <= (l - 1); ++j) {
      x = v[i][j].x;
      y = v[i][j].y;
      pt = query(1, 1, q, y);
      if (pt > x) continue;
      modify(1, 1, q, pt, x, y);
    }
    ans += 1ll * q * r - s[1];
  }
  cout << ans << '\n';
  return 0;
}
