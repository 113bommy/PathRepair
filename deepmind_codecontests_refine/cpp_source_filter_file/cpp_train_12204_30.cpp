#include <bits/stdc++.h>
using namespace std;
int n;
long long ans, a[200010];
mt19937 eng(chrono::high_resolution_clock().now().time_since_epoch().count());
void checkPrime(long long p) {
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      res += p - a[i];
      continue;
    }
    res += min(a[i] % p, (p - (a[i] % p)));
  }
  ans = min(ans, res);
}
void factor(long long x) {
  long long x1 = x;
  for (int i = 2; 1LL * i * i <= x1; ++i) {
    if (x % i == 0) {
      checkPrime(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    checkPrime(x);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  ans = n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  uniform_int_distribution<int> ds(0, n - 1);
  int steps = 0;
  auto t0 = chrono::high_resolution_clock().now();
  while (steps < 5000) {
    auto dt = chrono::high_resolution_clock().now() - t0;
    if (dt.count() > 1.5e9) {
      break;
    }
    int i = ds(eng);
    factor(a[i] + 1);
    factor(a[i]);
    if (a[i] > 2) {
      factor(a[i] - 1);
    }
    ++steps;
  }
  cout << ans;
}
