#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
int seg[MAXN * 4];
int a[MAXN], b[MAXN];
int x[MAXN], y[MAXN], z[MAXN];
int get(int qp, int xl = 0, int xr = MAXN, int id = 0) {
  if (qp < xl || qp >= xr) return -1;
  if (xr - xl == 1) return seg[id];
  int mid = (xl + xr) / 2;
  return max(max(get(qp, xl, mid, 2 * id + 1), get(qp, mid, xr, 2 * id + 2)),
             seg[id]);
}
void update(int ql, int qr, int qv, int xl = 0, int xr = MAXN, int id = 0) {
  ;
  if (ql <= xl && xr <= qr) {
    seg[id] = qv;
    return;
  }
  if (qr <= xl || xr <= ql) return;
  int mid = (xl + xr) / 2;
  update(ql, qr, qv, xl, mid, 2 * id + 1);
  update(ql, qr, qv, mid, xr, 2 * id + 2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int nq;
  cin >> nq;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  fill(seg, seg + MAXN * 4, -1);
  for (int i = 0; i < nq; i++) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      cin >> x[i] >> y[i] >> z[i];
      z[i]--, x[i]--;
      update(z[i], z[i] + y[i], i);
    } else {
      cin >> x[i];
      x[i]--;
      int aa = get(x[i]);
      if (aa == -1)
        cout << b[x[i]] << '\n';
      else
        cout << a[x[i] + x[aa] - z[aa]] << '\n';
    }
  }
}
