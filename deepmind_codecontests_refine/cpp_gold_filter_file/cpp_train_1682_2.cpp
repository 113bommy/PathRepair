#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
int main() {
  int n, m;
  cin >> n >> m;
  long long x[n];
  vector<long long> diff;
  for (int i = 0; i < (n); ++i) {
    cin >> x[i];
    if (i > 0) {
      diff.push_back(x[i] - x[i - 1]);
    }
  }
  long long g;
  if (n > 2) {
    g = gcd(diff[0], diff[1]);
    for (int i = 1; i < n - 1; i++) {
      g = gcd(g, diff[i]);
    }
  } else
    g = diff[0];
  bool ok = false;
  long long ans = 0;
  for (int i = 0; i < (m); ++i) {
    long long p;
    cin >> p;
    if (g % p == 0) {
      ok = true;
      ans = i + 1;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    cout << x[0] << " " << ans << endl;
  } else {
    cout << "NO" << endl;
  }
}
