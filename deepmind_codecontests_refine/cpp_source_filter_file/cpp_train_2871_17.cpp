#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long a[200011];
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n / 2; i += 2) swap(a[i], a[n - 1 - i]);
  for (long long i = 0; i < n; ++i) cout << a[i];
  return 0;
}
