#include <bits/stdc++.h>
using namespace std;
long long a[110][110];
int main() {
  long long n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  x--, y--;
  if (n == 1) {
    long long c = k / m;
    for (long long i = 0; i < m; i++) a[0][i] += c;
    c = k % m;
    for (long long i = 0; i < c; i++) a[0][i]++;
    long long mx = a[0][0], mn = a[0][0];
    for (long long i = 0; i < m; i++)
      mx = max(mx, a[0][i]), mn = min(mn, a[0][i]);
    cout << mx << ' ' << mn << ' ' << a[x][y] << '\n';
    return 0;
  }
  long long dwra = 2 * m + 2 * (n - 2) * m;
  long long c = k / dwra;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i == 0 || i == n - 1)
        a[i][j] += c;
      else
        a[i][j] += 2 * c;
    }
  }
  c = k % dwra;
  long long i = -1, j, cc = 0;
  bool flp = false;
  for (;;) {
    if (flp)
      i--;
    else
      i++;
    if (cc == c) break;
    for (j = 0; j < m; j++) {
      if (cc == c) break;
      cc++;
      a[i][j]++;
    }
    if (i == n - 1 && !flp) flp = true;
  }
  long long mx = a[0][0], mn = a[0][0];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) mx = max(mx, a[i][j]), mn = min(mn, a[i][j]);
  }
  cout << mx << ' ' << mn << ' ' << a[x][y] << '\n';
  return 0;
}
