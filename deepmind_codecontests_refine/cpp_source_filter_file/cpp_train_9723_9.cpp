#include <bits/stdc++.h>
using namespace std;
struct Hash {
  int x, i, t;
  Hash(int a = 0, int b = 0, int c = 0) { x = a, i = b, t = c; }
} H[200100 << 1];
struct query {
  int t, l, r;
} q[200100];
typedef int arr[200100];
arr f, lx, rx, num, pl, pr;
int n, tot, t, val, it, i;
vector<int> s[200100 << 2];
int gi() {
  int s = 0, p = 1;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') p = -1, c = getchar();
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * p;
}
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
int Union(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return fx;
  f[fy] = fx;
  lx[fx] = min(lx[fy], lx[fx]);
  rx[fx] = max(rx[fy], rx[fx]);
  return fx;
}
void Merge(int x, int l, int r, int p) {
  int sz = s[x].size();
  for (int i = 0; i < sz; i++) it = Union(it, s[x][i]);
  s[x].clear();
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    Merge((x << 1), l, mid, p);
  else
    Merge((x << 1 | 1), mid + 1, r, p);
}
void Updata(int x, int l, int r, int xl, int xr, int v) {
  if (xl <= l && r <= xr) {
    s[x].push_back(v);
    return;
  }
  int mid = (l + r) >> 1;
  if (xr <= mid)
    Updata((x << 1), l, mid, xl, xr, v);
  else if (xl > mid)
    Updata((x << 1 | 1), mid + 1, r, xl, xr, v);
  else
    Updata((x << 1), l, mid, xl, mid, v),
        Updata((x << 1 | 1), mid + 1, r, mid + 1, xr, v);
}
bool cmp(Hash a, Hash b) { return a.x < b.x; }
void Outp(int x) {
  if (x)
    printf("Yes\n");
  else
    printf("No\n");
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    q[i].t = gi(), q[i].l = gi(), q[i].r = gi();
    if (q[i].t == 2) continue;
    H[++t] = Hash(q[i].l, i, 0);
    H[++t] = Hash(q[i].r, i, 1);
  }
  sort(H + 1, H + t + 1, cmp);
  H[0].x = -1000000001;
  for (i = 1; i <= t; i++) {
    if (H[i].x != H[i - 1].x) ++val;
    if (H[i].t)
      q[H[i].i].r = val;
    else
      q[H[i].i].l = val;
  }
  for (i = 1; i <= n; i++) {
    if (q[i].t == 2) continue;
    num[i] = ++tot, f[tot] = tot;
    lx[tot] = pl[tot] = q[i].l;
    rx[tot] = pr[tot] = q[i].r;
  }
  for (i = 1; i <= n; i++) {
    if (q[i].t == 1) {
      it = find(num[i]);
      Merge(1, 1, val, q[i].l);
      Merge(1, 1, val, q[i].r);
      if (lx[it] + 1 < rx[it]) Updata(1, 1, val, lx[it] + 1, rx[it] - 1, it);
    } else {
      int fx = find(q[i].l), fy = find(q[i].r);
      Outp(fx == fy || (lx[fx] > lx[fy] && lx[fx] < rx[fy]) ||
           (rx[fx] > lx[fy] && rx[fx] < rx[fy]));
    }
  }
  return 0;
}
