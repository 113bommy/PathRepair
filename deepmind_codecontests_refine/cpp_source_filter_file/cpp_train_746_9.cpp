#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k < (n * n + n) / 2) return cout << -1, 0;
  long long t = k;
  k -= (n * n + n) / 2;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) a[i] = i;
  for (long long i = 1; i <= n / 2; i++) {
    if (k - (n + 1 - 2 * i) > 0) {
      swap(a[i], a[n - i + 1]);
      k -= (n + 1 - 2 * i);
    } else {
      swap(a[i], a[i + k]);
      cout << k << endl;
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
      for (long long i = 1; i <= n; i++) cout << a[i] << " ";
      return 0;
    }
  }
  cout << t - k << endl;
  for (long long i = 1; i <= n; i++) cout << i << " ";
  cout << endl;
  for (long long i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
