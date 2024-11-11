#include <bits/stdc++.h>
using namespace std;
const int maxn = 1211111;
int n, m;
int d[maxn], h[maxn];
struct Node {
  long long lx;
  long long rx;
  long long dis;
  long long ans;
} sum[maxn << 2];
Node cmop(Node a, Node b, int rt) {
  Node ret;
  ret.dis = rt + a.dis + b.dis;
  ret.lx = max(a.lx, b.lx + a.dis + rt);
  ret.rx = max(b.rx, a.rx + b.dis + rt);
  ret.ans = max(max(a.ans, b.ans), a.rx + b.lx + rt);
  return ret;
}
void Build(int l, int r, int rt) {
  if (l == r) {
    sum[rt].ans = 0;
    sum[rt].lx = sum[rt].rx = 2LL * h[l];
    sum[rt].dis = 0;
  } else {
    int mid = l + r >> 1;
    Build(l, mid, rt << 1);
    Build(mid + 1, r, rt << 1 | 1);
    sum[rt] = cmop(sum[rt << 1], sum[rt << 1 | 1], d[mid]);
  }
}
Node Query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return sum[rt];
  } else {
    int mid = l + r >> 1;
    Node pt;
    if (L <= mid)
      pt = Query(L, R, l, mid, rt << 1);
    else
      return Query(L, R, mid + 1, r, rt << 1 | 1);
    if (R > mid)
      return cmop(pt, Query(L, R, mid + 1, r, rt << 1 | 1), d[mid]);
    else
      return pt;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = n + 1; i < 2 * n; i++) {
    d[i] = d[i - n];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i], h[i + n] = h[i];
  }
  Build(1, 2 * n - 1, 1);
  int x, y, l, r;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    if (x > y)
      l = y + 1, r = x - 1;
    else
      l = y + 1, r = x + n - 1;
    if (l <= r) {
      cout << Query(l, r, 1, 2 * n - 1, 1).ans << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
