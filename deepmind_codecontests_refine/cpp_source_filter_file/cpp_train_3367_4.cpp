#include <bits/stdc++.h>
using namespace std;
const int M = 2000005;
const int N = 100005;
int ls[M], rs[M], sum[M];
int limit, sz, rt[N];
void insert(int &k, int l, int r, int p) {
  if (k <= limit) {
    ls[++sz] = ls[k];
    rs[sz] = rs[k];
    sum[sz] = sum[k];
    k = sz;
  }
  sum[k]++;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (p <= mid)
    insert(ls[k], l, mid, p);
  else
    insert(rs[k], mid + 1, r, p);
}
int ask(int k, int l, int r, int x, int y) {
  if (!k || (l == x && r == y)) return sum[k];
  int mid = (l + r) / 2;
  if (y <= mid) return ask(ls[k], l, mid, x, y);
  if (x > mid) return ask(rs[k], mid + 1, r, x, y);
  return ask(ls[k], l, mid, x, mid) + ask(rs[k], mid + 1, r, mid + 1, y);
}
int n, k;
struct P {
  int X, Y;
} a[N], b[N];
int X[N], Y[N * 2];
vector<int> vec[N];
bool ask(int lx, int rx, int ly, int ry) {
  lx = lower_bound(X + 1, X + *X + 1, lx) - X;
  rx = upper_bound(X + 1, X + *X + 1, rx) - X - 1;
  ly = lower_bound(Y + 1, Y + *Y + 1, ly) - Y;
  ry = upper_bound(Y + 1, Y + *Y + 1, ry) - Y - 1;
  return ask(rt[rx], 1, *Y, ly, ry) != ask(rt[lx - 1], 1, *Y, ly, ry);
}
pair<int, int> mn[N], q[N * 2];
int t[N * 2];
void change(int x, int v) {
  for (; x <= *Y; x += x & (-x)) t[x] = max(t[x], v);
}
int ask(int x) {
  int ans = -((1 << 30) - 233);
  for (; x; x -= x & (-x)) ans = max(ans, t[x]);
  return ans;
}
void findclosest() {
  for (int i = (int)(1); i <= (int)(n); i++)
    mn[i] = pair<int, int>(((1 << 30) - 233) / 2, i);
  for (int T = (int)(0); T <= (int)(3); T++) {
    for (int i = (int)(1); i <= (int)(n); i++) {
      P tmp = (P){a[i].Y, -a[i].X};
      a[i] = tmp;
    }
    for (int i = (int)(1); i <= (int)(n); i++) {
      P tmp = (P){b[i].Y, -b[i].X};
      b[i] = tmp;
    }
    *Y = 0;
    for (int i = (int)(1); i <= (int)(n); i++) Y[++*Y] = a[i].Y;
    for (int i = (int)(1); i <= (int)(k); i++) Y[++*Y] = b[i].Y;
    sort(Y + 1, Y + *Y + 1);
    *Y = unique(Y + 1, Y + *Y + 1) - Y - 1;
    for (int i = (int)(1); i <= (int)(*Y); i++) t[i] = -((1 << 30) - 233);
    for (int i = (int)(1); i <= (int)(n); i++) q[i] = pair<int, int>(a[i].X, i);
    for (int i = (int)(1); i <= (int)(k); i++)
      q[n + i] = pair<int, int>(b[i].X, ~i);
    sort(q + 1, q + n + k + 1);
    for (int i = (int)(1); i <= (int)(n + k); i++) {
      int id = q[i].second;
      if (id < 0) {
        id = ~id;
        change(lower_bound(Y + 1, Y + *Y + 1, b[id].Y) - Y, b[id].X + b[id].Y);
      } else {
        int v = ask(lower_bound(Y + 1, Y + *Y + 1, a[id].Y) - Y);
        mn[id].first = min(mn[id].first, a[id].X + a[id].Y - v);
      }
    }
  }
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d%d", &a[i].X, &a[i].Y);
  for (int i = (int)(1); i <= (int)(k); i++) scanf("%d%d", &b[i].X, &b[i].Y);
  findclosest();
  for (int i = (int)(1); i <= (int)(n); i++)
    a[i] = (P){a[i].X + a[i].Y, a[i].X - a[i].Y};
  for (int i = (int)(1); i <= (int)(k); i++)
    b[i] = (P){b[i].X + b[i].Y, b[i].X - b[i].Y};
  *X = *Y = 0;
  for (int i = (int)(1); i <= (int)(k); i++) {
    X[++*X] = b[i].X;
    Y[++*Y] = b[i].Y;
  }
  X[++*X] = Y[++*Y] = ((1 << 30) - 233);
  X[++*X] = Y[++*Y] = -((1 << 30) - 233);
  sort(X + 1, X + *X + 1);
  sort(Y + 1, Y + *Y + 1);
  *X = unique(X + 1, X + *X + 1) - X - 1;
  *Y = unique(Y + 1, Y + *Y + 1) - Y - 1;
  for (int i = (int)(1); i <= (int)(k); i++) {
    int x = lower_bound(X + 1, X + *X + 1, b[i].X) - X;
    vec[x].push_back(i);
  }
  for (int i = (int)(1); i <= (int)(*X); i++) {
    rt[i] = rt[i - 1];
    for (int j = (int)(0); j <= (int)(vec[i].size() - 1); j++) {
      int id = vec[i][j];
      int y = lower_bound(Y + 1, Y + *Y + 1, b[id].Y) - Y;
      insert(rt[i], 1, *Y, y);
    }
    limit = sz;
  }
  sort(mn + 1, mn + n + 1, cmp);
  int l = 0, r = ((1 << 30) - 233) / 2, ans = ((1 << 30) - 233) / 2;
  while (l <= r) {
    int mid = (l + r) / 2;
    int lx = -(((1 << 30) - 233) / 4), rx = -lx;
    int ly = lx, ry = rx;
    bool ok = 0;
    for (int i = (int)(1); i <= (int)(n); i++) {
      int id = mn[i].second;
      int dis = mid - mn[i].first;
      if (dis >= 0) {
        ok |= ask(lx - dis, rx + dis, ly - dis, ry + dis);
        if (ok) break;
      }
      lx = max(lx, a[id].X - mid);
      rx = min(rx, a[id].X + mid);
      ly = max(ly, a[id].Y - mid);
      ry = min(ry, a[id].Y + mid);
      if (lx > rx || ly > ry) break;
    }
    ok |= (lx <= rx && ly <= ry);
    if (ok)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
