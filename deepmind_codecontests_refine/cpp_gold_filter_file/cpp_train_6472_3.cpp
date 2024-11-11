#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e5 + 5;
long long n;
long long a[3003][3003];
long long f[3003][3003];
long long m, p, q;
long long g0, x, y, z;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p >> q;
  cin >> g0 >> x >> y >> z;
  long long xx = 1, yy = 1;
  while (xx != n || yy != m) {
    a[xx][yy] = g0;
    g0 = (g0 * x + y) % z;
    yy++;
    if (yy == m + 1) {
      yy = 1;
      xx++;
    }
  }
  a[xx][yy] = g0;
  for (long long i = 1; i <= n; i++) {
    deque<long long> de;
    for (long long j = 1; j <= m; j++) {
      while (!de.empty() && a[i][de.back()] > a[i][j]) de.pop_back();
      de.push_back(j);
      if (de.front() <= j - q) de.pop_front();
      f[i][j] = de.front();
    }
    de.clear();
  }
  long long res = 0;
  for (long long j = q; j <= m; j++) {
    deque<long long> de;
    for (long long i = 1; i <= n; i++) {
      while (!de.empty() && a[de.back()][f[de.back()][j]] > a[i][f[i][j]])
        de.pop_back();
      de.push_back(i);
      if (de.front() <= i - p) de.pop_front();
      if (i >= p) {
        res += a[de.front()][f[de.front()][j]];
      }
    }
    de.clear();
  }
  cout << res;
}
