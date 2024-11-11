#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
inline int gi() {
  int ans = 0, c;
  while (!isdigit(c = getchar()))
    ;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans;
}
struct node {
  int x, l, r, d;
  bool operator<(const node &p) const { return x < p.x; }
} e[N];
struct ak {
  int ls, rs, w, la, fi;
} tr[N * 30];
int n, m, k, K, rt = 0, tt = 0;
inline int lowbit(int l, int r) {
  l--;
  int ret = 0;
  for (int i = 1; i <= k; i <<= 1)
    ret |=
        (((r / i - l / i) - (i * 2 <= k ? r / i / 2 - l / i / 2 : 0)) & 1) * i;
  return ret;
}
inline void upd(int o) {
  if (tr[o].la)
    tr[o].w = tr[o].fi;
  else
    tr[o].w = tr[tr[o].ls].w ^ tr[tr[o].rs].w;
}
inline void Modify(int &o, int l, int r, int sa, int se, int t) {
  if (!o) o = ++tt, tr[o].fi = lowbit(l, r);
  if (sa <= l && r <= se) {
    tr[o].la += t;
    upd(o);
    return;
  }
  int mid = (l + r) >> 1;
  if (se <= mid)
    Modify(tr[o].ls, l, mid, sa, se, t);
  else if (sa > mid)
    Modify(tr[o].rs, mid + 1, r, sa, se, t);
  else
    Modify(tr[o].ls, l, mid, sa, mid, t),
        Modify(tr[o].rs, mid + 1, r, mid + 1, se, t);
  upd(o);
}
int main() {
  cin >> n >> m >> k;
  for (K = 1; K <= k; K <<= 1)
    ;
  int xl, xr, yl, yr, cnt = 0, x, y, sum = 0, ans = 0;
  for (int i = 1; i <= m; i++) {
    xl = gi();
    yl = gi();
    xr = gi();
    yr = gi();
    e[++cnt] = (node){xl, yl, yr, 1};
    e[++cnt] = (node){xr + 1, yl, yr, -1};
  }
  sort(e + 1, e + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    if (e[i].x != e[i - 1].x) {
      x = lowbit(e[i - 1].x, e[i].x - 1);
      y = tr[rt].w;
      xl = xr = sum = 0;
      for (int j = K; j; j >>= 1) {
        sum = -xl * xr;
        xl += ((x & j) > 0);
        xr += ((y & j) > 0);
        sum += xl * xr;
        if (sum & 1) ans ^= j;
      }
    }
    Modify(rt, 1, n, e[i].l, e[i].r, e[i].d);
  }
  if (ans)
    puts("Malek");
  else
    puts("Hamed");
  return 0;
}
