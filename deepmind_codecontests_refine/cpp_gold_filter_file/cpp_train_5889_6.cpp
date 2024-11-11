#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n][m];
  long long p[n], q[n], y[m], z[m];
  long long l[n], r[n], d[m], u[m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    l[i] = 0;
    r[i] = 0;
  }
  for (long long i = 0; i < m; i++) {
    d[i] = 0;
    u[i] = 0;
  }
  for (long long i = 0; i < n; i++) {
    p[i] = 1000000007;
    q[i] = -1;
  }
  for (long long i = 0; i < m; i++) {
    y[i] = -1;
    z[i] = 1000000007;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        l[i] = 1;
        p[i] = min(j, p[i]);
        r[i] = 1;
        q[i] = max(j, q[i]);
        d[j] = 1;
        y[j] = max(i, y[j]);
        u[j] = 1;
        z[j] = min(i, z[j]);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        if (l[i] == 1 && j > p[i] && j != 0) {
          ans += 1;
        }
        if (r[i] == 1 && j < q[i] && j != (m - 1)) {
          ans += 1;
        }
        if (d[j] == 1 && i < y[j] && i != (n - 1)) {
          ans += 1;
        }
        if (u[j] == 1 && i > z[j] && i != 0) {
          ans += 1;
        }
      }
    }
  }
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
