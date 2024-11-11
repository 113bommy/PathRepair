#include <bits/stdc++.h>
using namespace std;
long long mod = 1e18 + 9;
long long poww(long long x, long long y) {
  if (y == 0) return 1;
  if (x == 1) return 1;
  if (x == 0) return 0;
  if (y == 1) return x;
  long long d = poww(x, y / 2);
  d %= mod;
  if (y % 2) return (((d * d) % mod) * x) % mod;
  return (d * d) % mod;
}
vector<pair<int, int> > adj;
pair<int, int> ad;
int main() {
  long long n, m;
  cin >> n >> m;
  long long q = m;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long x = 1;
  if (n == 1) {
    cout << a[n - 1] + m << " " << a[n - 1] + m;
    return 0;
  }
  for (long long i = n - 2; i >= 0; i--) {
    if (a[i] == a[i + 1] && x != 0) {
      continue;
    } else {
      x = 0;
      m -= (a[n - 1] - a[i]);
    }
  }
  long long y;
  if (m <= 0)
    cout << a[n - 1] << " ";
  else {
    if (m % n == 0)
      y = 0;
    else
      y = 1;
    cout << a[n - 1] + (m / n + y) << " ";
  }
  cout << a[n - 1] + q;
  return 0;
}
