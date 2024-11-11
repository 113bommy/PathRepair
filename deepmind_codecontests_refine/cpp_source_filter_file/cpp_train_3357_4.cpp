#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 1;
long long k = 380;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long i = 0;
  long long l = 0, r = 1e9 + 1;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (n * (mid + 1) - mid - 1 < k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << n * r + k - (n * r - r) << '\n';
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
