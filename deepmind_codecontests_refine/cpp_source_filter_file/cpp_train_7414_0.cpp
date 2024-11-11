#include <bits/stdc++.h>
using namespace std;
long long fast_pow(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> v(n + 1);
  v[0] = 0;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = x;
  }
  sort(a, a + n);
  long long ans = 0;
  long long sum = 0;
  for (long long i = 0; i < k - 1; i++) {
    v[i + 1] = a[i];
    sum += a[i];
    if (sum <= m) ans = i + 1;
  }
  for (long long i = k - 1; i < n; i++) {
    v[i + 1] = a[i] + v[i - k + 1];
    if (v[i + 1] <= m) ans = i + 1;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
