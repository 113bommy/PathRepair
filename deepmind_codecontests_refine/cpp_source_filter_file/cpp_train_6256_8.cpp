#include <bits/stdc++.h>
using namespace std;
int tr[1 << 22], lazy[1 << 22];
void propagate(int i, int l, int r) {
  if (lazy[i] == -1) return;
  tr[i] = lazy[i];
  if (l != r) lazy[i << 1] = lazy[i << 1 | 1] = lazy[i];
  lazy[i] = -1;
}
void update(int i, int l, int r, int a, int b, int v) {
  propagate(i, l, r);
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    lazy[i] = v;
    propagate(i, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(i << 1, l, mid, a, b, v);
  update(i << 1 | 1, mid + 1, r, a, b, v);
}
int get(int i, int l, int r, int a, int b) {
  propagate(i, l, r);
  if (l > b || r < a) return -1;
  if (l >= a && r <= b) return tr[i];
  int mid = (l + r) >> 1;
  return max(get(i << 1, l, mid, a, b), get(i << 1 | 1, mid + 1, r, a, b));
}
int main() {
  cin.sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> mn(q + 1, 2 * q), mx(q + 1, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn[a[i]] = min(mn[a[i]], i);
    mx[a[i]] = max(mx[a[i]], i);
  }
  for (int i = 0; i < (1 << 22); i++) lazy[i] = -1, tr[i] = 1;
  for (int i = 2; i <= q; i++) update(1, 0, n - 1, mn[i], mx[i], i);
  vector<int> res(n);
  bool ok = 1;
  int zer = -1;
  for (int i = 0; i < n; i++) {
    res[i] = get(1, 0, n - 1, i, i);
    if (!a[i]) zer = i;
    if (a[i] && a[i] != res[i]) {
      ok = 0;
      break;
    }
  }
  if (mx[q] == -1) {
    if (zer == -1)
      ok = 0;
    else
      res[zer] = q;
  }
  if (!ok)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
  }
  return 0;
}
