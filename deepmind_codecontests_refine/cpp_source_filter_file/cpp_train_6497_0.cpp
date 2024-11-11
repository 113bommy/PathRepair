#include <bits/stdc++.h>
using namespace std;
const long long N = 2001;
long long a[N], n, k;
long long f[N];
bool ok(long long x) {
  for (long long i = 2; i <= n; ++i) {
    f[i] = n;
    for (long long j = 1; j < i; ++j)
      if (abs(a[i] - a[j]) <= (i - j) * x) f[i] = min(f[i], f[j] + i - j - 1);
  }
  for (long long i = 2; i <= n; ++i) f[i] = min(f[i], f[i - 1] + 1);
  return f[n] <= k;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  long long L = 0, R = 1e9;
  while (L < R) {
    long long M = (L + R) / 2;
    if (ok(M))
      R = M;
    else
      L = M + 1;
  }
  cout << L << endl;
}
