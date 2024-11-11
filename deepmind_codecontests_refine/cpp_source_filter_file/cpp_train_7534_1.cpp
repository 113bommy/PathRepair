#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 100, S = 4 * N + 100;
int n, tq;
int a[N], b[N], seg[S], x[N], y[N], k[N];
void upd(int s, int e, int k, int l = 0, int r = n, int id = 1) {
  if (l >= e || r <= s) return;
  if (l >= s && r <= e) {
    seg[id] = k;
    return;
  }
  int L = id << 1, R = L | 1, m = l + r >> 1;
  upd(s, r, k, l, m, L);
  upd(s, r, k, m, r, R);
}
int get(int k, int l = 0, int r = n, int id = 1) {
  if (k < l || k >= r) return 0;
  if (r - l == 1) return seg[id];
  int L = id << 1, R = L | 1, m = l + r >> 1;
  int gl = get(k, l, m, L);
  int gr = get(k, m, r, R);
  return max(seg[id], max(gl, gr));
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> tq;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 1, qm, d; i <= tq; i++) {
    cin >> qm;
    if (qm == 1) {
      cin >> x[i] >> y[i] >> k[i];
      x[i]--, y[i]--;
      upd(y[i], min(n, y[i] + k[i]), i);
    } else {
      cin >> d;
      d--;
      int j = get(d);
      if (!j)
        cout << b[d] << '\n';
      else
        cout << a[x[j] + d - y[j]] << '\n';
    }
  }
}
