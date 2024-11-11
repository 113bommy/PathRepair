#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long INF = 1e9;
signed main() {
  long long n, k, x;
  cin >> n >> k >> x;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[n - i - 1];
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    if (a[i] > x && k) {
      k--;
      sum += x;
    } else {
      sum += a[i];
    }
  }
  cout << sum;
  return 0;
}
