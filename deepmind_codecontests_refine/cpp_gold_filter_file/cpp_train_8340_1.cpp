#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const long long modd1 = 1e9 + 7, modd2 = 998244353, maxn = 10;
const double pi = acos(-1);
void solve() {
  long long n, i, j, m;
  cin >> n;
  long long b[n / 2 + 3];
  for (i = 1; i <= n / 2; ++i) {
    cin >> b[i];
  }
  long long mn = 0, a[n + 4];
  for (i = 1; i <= n / 2; ++i) {
    a[i] = mn;
    a[n + 1 - i] = b[i] - a[i];
    if (a[n + 1 - i] > a[n + 2 - i]) {
      long long xet = a[n + 1 - i] - a[n + 2 - i];
      a[i] += xet;
      a[n + 1 - i] = a[n + 2 - i];
      mn = a[i];
    }
  }
  for (i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
