#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int a[N][N];
int m, n, x, X;
int best;
int up(int x, int y) {
  x = x ^ y;
  return x == 0 ? 1 : -1;
}
int bit(int p, int v) { return (p >> v) & 1; }
void check(int p) {
  int ans = 0;
  int tmp0, tmp1;
  int tmp00, tmp01, tmp10, tmp11;
  int c00, c01, c10, c11;
  int r0, r1;
  for (int i = 0; i < x; ++i)
    if (bit(p, i))
      ans += -a[i][m];
    else
      ans += a[i][m];
  for (int i = x; i < n; ++i) ans += a[i][m] * up(bit(p, i - x), bit(p, m));
  c00 = up(0, 0);
  c01 = up(0, 1);
  c10 = up(1, 0);
  c11 = up(1, 1);
  for (int c = 0; c < m; ++c) {
    tmp0 = a[m][c] + up(0, bit(p, m)) * a[m][c + x];
    tmp1 = -a[m][c] + up(1, bit(p, m)) * a[m][c + x];
    for (int r = 0; r < m; ++r) {
      r0 = up(0, bit(p, r));
      r1 = up(1, bit(p, r));
      tmp00 = a[r][c] + r0 * a[r][c + x] + c00 * a[r + x][c] +
              a[r + x][c + x] * up(0 ^ bit(p, m), 0 ^ bit(p, r));
      tmp10 = -a[r][c] + r1 * a[r][c + x] + c10 * a[r + x][c] +
              a[r + x][c + x] * up(0 ^ bit(p, m), 1 ^ bit(p, r));
      tmp01 = a[r][c] + r0 * a[r][c + x] + c01 * a[r + x][c] +
              a[r + x][c + x] * up(1 ^ bit(p, m), 0 ^ bit(p, r));
      tmp11 = -a[r][c] + r1 * a[r][c + x] + c11 * a[r + x][c] +
              a[r + x][c + x] * up(1 ^ bit(p, m), 1 ^ bit(p, r));
      tmp0 += max(tmp00, tmp10);
      tmp1 += max(tmp01, tmp11);
    }
    ans += max(tmp0, tmp1);
  }
  best = max(best, ans);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  x = (n + 1) / 2;
  m = x - 1;
  best = -(int)1e9;
  X = 1 << x;
  for (int mask = 0; mask < X; ++mask) check(mask);
  cout << best << endl;
}
