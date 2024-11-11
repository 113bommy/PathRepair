#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 2;
long long a[N], f[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  a[n + 1] = 1e18;
  a[0] = 1;
  for (long long i = n; i; --i) cin >> a[i];
  for (long long i = n; i; --i) a[i] = min(a[i], a[i + 1]);
  for (long long i = 1; i <= n; ++i) {
    long long x = a[i];
    long long S = 0;
    long long &C = f[i];
    while (x) {
      long long j = lower_bound(a + 1, a + n, x) - a - 1;
      C = max((n - j) * (x - x % a[j] - a[j]) + S + f[j], C);
      S = S + (n - j) * (x - x % a[j]);
      x = x % a[j];
    }
  }
  cout << f[n] << endl;
}
