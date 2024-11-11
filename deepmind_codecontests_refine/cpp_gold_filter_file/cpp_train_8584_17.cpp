#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, G = 60;
int seg[4 * MAXN][G];
int a[MAXN];
inline void pull(int x) {
  int l = 2 * x, r = l + 1;
  for (int i = 0; i < G; i++) {
    int next = (seg[l][i] + i) % G;
    seg[x][i] = seg[r][next] + seg[l][i];
  }
}
void upd(int x, int xl, int xr, int ind, int q) {
  if (ind >= xr || ind < xl) return;
  if (xr - xl == 1) {
    a[xl] = q;
    for (int i = 0; i < G; i++) {
      seg[x][i] = 1;
      if (i % a[xl] == 0) seg[x][i]++;
    }
    return;
  }
  int mid = (xr + xl) / 2, l = 2 * x, r = l + 1;
  upd(l, xl, mid, ind, q);
  upd(r, mid, xr, ind, q);
  pull(x);
}
int get(int x, int xl, int xr, int ql, int qr, int q) {
  if (xl >= qr || xr <= ql) return 0;
  if (xl >= ql && xr <= qr) {
    return seg[x][q];
  }
  int mid = (xl + xr) / 2, l = 2 * x, r = l + 1;
  int u = get(l, xl, mid, ql, qr, q), v = get(r, mid, xr, ql, qr, (u + q) % G);
  return u + v;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    upd(1, 0, n, i, a[i]);
  }
  int m;
  cin >> m;
  while (m--) {
    char com;
    int l, r;
    cin >> com >> l >> r;
    if (com == 'A') {
      l--;
      r--;
      cout << get(1, 0, n, l, r, 0) << "\n";
    } else {
      l--;
      upd(1, 0, n, l, r);
    }
  }
}
