#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const long double INF = 1e30;
int rek[N][N], n, a, b;
long double c, p[N], q[N], dp[N][N];
long double f(int i, int x) {
  if (x < 0) return -INF;
  if (dp[i][x] != -1.0) return dp[i][x];
  if (i == n) return 0;
  long double ret = 0;
  if (f(i + 1, x) > ret) ret = f(i + 1, x), rek[i][x] = 0;
  if (x > 0 && f(i + 1, x - 1) + p[i] > ret)
    ret = f(i + 1, x - 1) + p[i], rek[i][x] = 1;
  if (f(i + 1, x) + q[i] - c > ret) ret = f(i + 1, x) + q[i] - c, rek[i][x] = 2;
  if (x > 0 && f(i + 1, x - 1) + p[i] + q[i] - p[i] * q[i] - c > ret)
    ret = f(i + 1, x - 1) + p[i] + q[i] - p[i] * q[i] - c, rek[i][x] = 3;
  return dp[i][x] = ret;
}
int check(int en = 0) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= a; j++) dp[i][j] = -1;
  long double sol = f(0, a);
  int ci = 0, ca = a, cb = 0;
  while (ci != n) {
    if (rek[ci][ca] == 2 || rek[ci][ca] == 3) cb++;
    if (rek[ci][ca] == 1 || rek[ci][ca] == 3) ca--;
    ci++;
  }
  if (en)
    cout << fixed << setprecision(10) << sol + c * (long double)cb << " "
         << endl;
  return cb;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  if (a == b && b == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> q[i];
  long double lo = 0, hi = 1.1;
  for (int i = 0; i < 50; i++) {
    c = (lo + hi) / 2;
    int x = check();
    if (x <= b) {
      hi = c;
    } else {
      lo = c;
    }
  }
  c = hi;
  check(1);
}
