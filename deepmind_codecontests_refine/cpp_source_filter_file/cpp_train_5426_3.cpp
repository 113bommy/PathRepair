#include <bits/stdc++.h>
using namespace std;
const long long mx = 1e5 + 66;
const long long mod = 1e9 + 7;
const long long inf = 8e18 + 66;
const int llg = 17;
const long long mxk = 31700000;
long long power(long long a, long long b, long long md) {
  if (b == 0) return 1;
  long long c = power(a, b / 2, md);
  if (b % 2)
    return c * c % md * a % md;
  else
    return c * c % md;
}
int n, a[mx], la[mx], ra[mx], rmq[2][llg][mx], val[2][mx], lga[mx], l[llg][mx],
    r[llg][mx];
int cmx(int x, int y, int b) {
  if (val[b][x] < val[b][y]) return y;
  return x;
}
void build(int b) {
  for (int i = 1; i < 3 * n + 1; i++) {
    rmq[b][0][i] = i;
    if (b == 0)
      val[b][i] = -la[i];
    else
      val[b][i] = ra[i];
  }
  for (int i = 1; i < lga[3 * n] + 1; i++)
    for (int j = 1; j + (1 << i) - 1 <= 3 * n; j++) {
      rmq[b][i][j] =
          cmx(rmq[b][i - 1][j], rmq[b][i - 1][j + (1 << (i - 1))], b);
    }
}
int maxq(int x, int y, int b) {
  int k = lga[y - x + 1];
  return cmx(rmq[b][k][x], rmq[b][k][y - (1 << k) + 1], b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i < mx; i++) {
    lga[i] = lga[i / 2] + 1;
  }
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    a[i + n * 2] = a[i + n] = a[i];
  }
  for (int i = 1; i < 3 * n + 1; i++) {
    la[i] = max(1, i - a[i]);
    ra[i] = min(3 * n, a[i] + i);
  }
  for (int i = 0; i < lga[3 * n] + 1; i++) {
    l[i][1] = 1;
    r[i][3 * n] = 3 * n;
  }
  for (int i = 1; i < 3 * n + 1; i++) {
    l[0][i] = la[i];
    r[0][i] = ra[i];
  }
  build(0);
  build(1);
  for (int i = 1; i < lga[n * 3] + 1; i++) {
    for (int j = 1; j < 3 * n + 1; j++) {
      int al = maxq(l[i - 1][j], r[i - 1][j], 0);
      int ar = maxq(l[i - 1][j], r[i - 1][j], 1);
      l[i][j] = min(l[i - 1][al], l[i - 1][ar]);
      r[i][j] = max(r[i - 1][al], r[i - 1][ar]);
    }
  }
  for (int i = n + 1; i < 2 * n + 1; i++) {
    int ans = 1, u = i, v = i;
    for (int j = lga[3 * n]; j >= 0; j--) {
      if (max(r[j][u], r[j][v]) - min(l[j][u], l[j][v]) < n - 1) {
        int al = maxq(l[j][u], r[j][v], 0);
        int ar = maxq(l[j][u], r[j][v], 1);
        u = al, v = ar, ans += (1 << j);
      }
    }
    cout << ans << ' ';
  }
}
