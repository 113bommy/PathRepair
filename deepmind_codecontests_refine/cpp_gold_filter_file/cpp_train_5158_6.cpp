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
  long long x, y, z = 0, f = 0;
  if (m < n) {
    swap(m, n);
  }
  for (long long i = 1; i <= n; i++) {
    y = i / 5;
    x = (y + 1) * 5 - i;
    if (x <= m) {
      f = ((m - x) / 5) + 1;
    }
    z += f;
  }
  cout << z;
  return 0;
}
