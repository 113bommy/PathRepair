#include <bits/stdc++.h>
std::mt19937_64 rng(
    std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> v(n, 0);
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = 0; i <= n; i++) {
      if (i == 0) {
        if (s >= x * n) {
          ans = max(ans, n);
          break;
        }
      } else {
        s -= v[i - 1];
        if (s >= x * (n - i)) {
          ans = max(ans, n - i);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
