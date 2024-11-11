#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<long long> cr(n), cc(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      cr[i] += a[i][j], cc[j] += a[i][j];
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<long long> x(m), y(m);
    for (int j = 0; j < m; j++) x[j] = cc[j] - a[i][j], y[j] = cc[j];
    sort((x).rbegin(), (x).rend());
    sort((y).rbegin(), (y).rend());
    long long cur = cr[i];
    long long p = 0;
    for (int k = 0; k < min(3, m); k++) cur += x[k];
    for (int k = 0; k < min(4, m); k++) p += y[k];
    ans = max({ans, cur, p});
  }
  for (int j = 0; j < m; j++) {
    vector<long long> y(n), x(n);
    for (int i = 0; i < n; i++) y[i] = cr[i] - a[i][j], x[i] = cr[i];
    sort((y).rbegin(), (y).rend());
    sort((x).rbegin(), (x).rend());
    long long cur = cc[j];
    long long p = 0;
    for (int k = 0; k < min(3, n); k++) cur += y[k];
    for (int k = 0; k < min(4, n); k++) p += x[k];
    ans = max({ans, cur, p});
  }
  if (n > m) {
    vector<vector<int>> b(m, vector<int>(n));
    cr.assign(m, 0);
    cc.assign(n, 0);
    int x = 0, y = 0;
    for (int j = 0; j < m; j++) {
      for (int i = n - 1; i >= 0; i--) {
        b[x][y] = a[i][j];
        y++;
      }
      x++, y = 0;
    }
    swap(n, m);
    a = b;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cr[i] += a[i][j], cc[j] += a[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long cur = cr[i] + cr[j];
      vector<long long> u(m);
      long long mx1 = 0, mx2 = 0;
      for (int k = 0; k < m; k++) {
        u[k] = cc[k] - a[i][k] - a[j][k];
        if (u[k] >= mx1) {
          mx2 = mx1;
          mx1 = u[k];
        } else {
          mx2 = max(mx2, u[k]);
        }
      }
      ans = max(ans, cur + mx1 + mx2);
    }
  }
  cout << ans;
  return 0;
}
