#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 17;
const int INF = 1e9 + 17;
int n;
int seg[4 * MAXN], lazy[4 * MAXN];
int a[MAXN], b[MAXN];
void shift(int id) {
  seg[2 * id + 1] += lazy[id];
  lazy[2 * id + 1] += lazy[id];
  seg[2 * id + 2] += lazy[id];
  lazy[2 * id + 2] += lazy[id];
  lazy[id] = 0;
}
void update(int ql, int qr, int qv, int xl = 0, int xr = n, int id = 0) {
  if (ql == qr) return;
  if (ql <= xl && xr <= qr) {
    lazy[id] += qv;
    seg[id] += qv;
    return;
  }
  if (qr <= xl || xr <= ql) return;
  int mid = (xl + xr) / 2;
  shift(id);
  update(ql, qr, qv, xl, mid, 2 * id + 1);
  update(ql, qr, qv, mid, xr, 2 * id + 2);
  seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}
void build(int id = 0, int xl = 0, int xr = n) {
  if (xr - xl == 1) {
    seg[id] = xl + 1;
    return;
  }
  int mid = (xl + xr) / 2;
  build(2 * id + 1, xl, mid);
  build(2 * id + 2, mid, xr);
  seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k, h;
  cin >> k >> n >> h;
  build();
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(b, b + n);
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++)
    update(lower_bound(b, b + n, h - a[i]) - b, n, -1);
  int ans = 0;
  for (int i = n - 1; i < k; i++) {
    update(lower_bound(b, b + n, h - a[i]) - b, n, -1);
    ans += (seg[0] == 0);
    update(lower_bound(b, b + n, h - a[i - n + 1]) - b, n, 1);
  }
  cout << ans;
}
