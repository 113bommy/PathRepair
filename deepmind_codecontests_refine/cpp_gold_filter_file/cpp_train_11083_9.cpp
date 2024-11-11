#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
int arr[lim][31], qur[lim][3], fin[lim], seg[4 * lim], q, n;
void make() {
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
    for (int j = 0; j < 31; ++j)
      if ((qur[i][2] >> j) & 1) arr[qur[i][0]][j]++, arr[qur[i][1] + 1][j]--;
  }
  for (int i = 0; i < 31; ++i)
    for (int j = 1; j <= n; ++j) arr[j][i] += arr[j - 1][i];
  for (int i = 0; i < 31; ++i)
    for (int j = 1; j <= n; ++j) fin[j] |= (1 << i) * (arr[j][i] > 0);
}
void build(int x, int l, int r) {
  if (l == r) {
    seg[x] = fin[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * x + 1, l, m);
  build(2 * x + 2, m + 1, r);
  seg[x] = seg[2 * x + 1] & seg[2 * x + 2];
}
int query(int x, int l, int r, int a, int b) {
  if (b < l || r < a || r < l) return 0xFFFFFFFF;
  if (a <= l && r <= b) return seg[x];
  int m = (l + r) / 2;
  return query(2 * x + 1, l, m, a, b) & query(2 * x + 2, m + 1, r, a, b);
}
void check() {
  build(0, 1, n);
  int f = 1;
  for (int i = 0; i < q; ++i)
    f &= (query(0, 1, n, qur[i][0], qur[i][1]) == qur[i][2]);
  if (f) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << fin[i] << ' ';
  } else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  make();
  check();
  return 0;
}
