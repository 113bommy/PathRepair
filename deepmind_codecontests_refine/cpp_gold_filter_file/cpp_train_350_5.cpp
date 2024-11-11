#include <bits/stdc++.h>
using namespace std;
const int maxn = 1008611;
struct ST {
  int i, j, l, r, mid;
  vector<int> vv;
} st[maxn * 4];
int p1[maxn];
int p2[maxn];
int xx[maxn];
void bd(int d, int x, int y) {
  st[d].i = x, st[d].j = y;
  st[d].mid = (x + y) >> 1;
  st[d].vv.clear();
  for (int i = x; i <= y; i++) st[d].vv.push_back(xx[i]);
  sort(st[d].vv.begin(), st[d].vv.end());
  if (x < y) {
    st[d].l = d << 1;
    st[d].r = d << 1 | 1;
    bd(st[d].l, x, st[d].mid);
    bd(st[d].r, st[d].mid + 1, y);
  }
}
int query(int d, int x, int y, int l2, int r2) {
  if (x <= st[d].i && y >= st[d].j) {
    int ll =
        lower_bound(st[d].vv.begin(), st[d].vv.end(), l2) - st[d].vv.begin();
    int rr =
        upper_bound(st[d].vv.begin(), st[d].vv.end(), r2) - st[d].vv.begin();
    return rr - ll;
  } else {
    int temp = 0;
    if (x <= st[d].mid) temp += query(st[d].l, x, y, l2, r2);
    if (y > st[d].mid) temp += query(st[d].r, x, y, l2, r2);
    return temp;
  }
}
int n;
int rr = 0;
int f(int z) { return ((z - 1 + rr) % n) + 1; }
int tmp[maxn];
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", &p1[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &p2[i]);
    for (int i = 1; i <= n; i++) tmp[p2[i]] = i;
    for (int i = 1; i <= n; i++) xx[i] = tmp[p1[i]];
    int m;
    bd(1, 1, n);
    cin >> m;
    rr = 0;
    int a, b, c, d;
    while (m--) {
      scanf("%d%d%d%d", &a, &b, &c, &d);
      int l1, r1, l2, r2;
      l1 = min(f(a), f(b));
      r1 = max(f(a), f(b));
      l2 = min(f(c), f(d));
      r2 = max(f(c), f(d));
      rr = query(1, l1, r1, l2, r2);
      printf("%d\n", rr);
      rr++;
    }
  }
  return 0;
}
