#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> randGen;
void init_code() {}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << "\n";
    return;
  }
  if (y > x) {
    cout << (y - y % x) / 2 << "\n";
  }
  if (x > y) {
    cout << 2 * x + y << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
