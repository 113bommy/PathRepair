#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e18 + 7;
const long long N = 6e6 + 5;
long long a[N], b[N];
int main() {
  long long i, j, k, l = 0;
  long long n, m, t;
  cin >> n >> m;
  long long ans = 0, s = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (i = 1; i < n; i++) ans += a[i] * a[i - 1];
  ans += a[n - 1] * a[0];
  while (m--) {
    cin >> k;
    j = k - 1;
    t = k + 1;
    if (j < 0) j = n - 1;
    t %= n;
    ans += (s - a[j] - a[k] - a[t]) * a[k];
    s -= a[k];
    a[k] = 0;
  }
  cout << ans << endl;
  return 0;
}
