#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 300005;
int n, q;
int a[N], kq[N];
int T[8 * N], lz[8 * N];
struct Query {
  int l, r, id;
  friend bool operator<(Query x, Query y) { return x.r < y.r; }
} b[N];
void down(int id) {
  int x = lz[id];
  if (x == 0) return;
  T[id * 2] += x;
  T[id * 2 + 1] += x;
  lz[id * 2] += x;
  lz[id * 2 + 1] += x;
  lz[id] = 0;
}
int get(int id, int l, int r, int lim, int val) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  down(id);
  if (T[id * 2 + 1] >= val && mid < lim) {
    return get(id * 2 + 1, mid + 1, r, lim, val);
  } else
    return get(id * 2, l, mid, lim, val);
}
void up(int id, int l, int r, int pos, int val) {
  if (l > pos) return;
  if (r <= pos) {
    T[id] += val;
    lz[id] += val;
    down(id);
    return;
  }
  int mid = (l + r) / 2;
  down(id);
  up(id * 2, l, mid, pos, val);
  up(id * 2 + 1, mid + 1, r, pos, val);
  T[id] = max(T[id * 2], T[id * 2 + 1]);
}
int get_val(int id, int l, int r, int pos) {
  if (l == r) {
    return T[id];
  }
  int mid = (l + r) / 2;
  down(id);
  if (mid < pos)
    return get_val(id * 2 + 1, mid + 1, r, pos);
  else
    return get_val(id * 2, l, mid, pos);
}
void Solve() {
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0 && T[1] >= a[i]) {
      int x = get(1, 1, n, i, a[i]);
      up(1, 1, n, x, 1);
    }
    while (b[j].r == i && j <= q) {
      kq[b[j].id] = get_val(1, 1, n, b[j].l);
      j++;
    }
    if (j == q + 1) break;
  }
  for (int i = 1; i <= q; i++) cout << kq[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = i - a[i];
  for (int i = 1; i <= q; i++) {
    cin >> b[i].l >> b[i].r;
    b[i].l++;
    b[i].r = n - b[i].r;
    b[i].id = i;
  }
  sort(b + 1, b + q + 1);
  Solve();
  return 0;
}
