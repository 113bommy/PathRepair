#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5;
const long long inf = 1e18;
long long add(long long a, long long b) {
  long long res = (a + b) % mod;
  return (res < 0) ? res + mod : res;
}
long long mul(long long a, long long b) {
  long long res = (a * 1LL * b) % mod;
  return (res < 0) ? res + mod : res;
}
bool compare(long long x, long long y) { return x > y; }
long long h[2][N + 5];
void solve() {
  long long n, k, m;
  cin >> n >> k;
  long long a[k][k];
  memset(a, 0, sizeof a);
  long long x, yl, yr, xc, yc, f;
  xc = yc = k / 2;
  for (long long i = 0; i < n; i++) {
    cin >> m;
    f = -1;
    for (long long j = 0; j < k; j++) {
      long long l = 0, r = 0;
      long long tempf = 0;
      while (r < k) {
        if (a[j][r] == 1) {
          tempf = 0;
          l = r = r + 1;
          continue;
        }
        while (r < k && a[j][r] == 0) {
          tempf += abs(r - yc) + abs(j - xc);
          long long len = r - l + 1;
          if (len == m) {
            if (f == -1 || tempf < f) {
              f = tempf, x = j, yl = l, yr = r;
            }
            tempf -= (abs(yc - l) + abs(j - xc));
            l++;
          }
          r++;
        }
      }
    }
    if (f == -1)
      cout << -1 << "\n";
    else {
      cout << x + 1 << " " << yl + 1 << " " << yr + 1 << "\n";
      for (long long j = yl; j <= yr; j++) a[x][j] = 1;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
