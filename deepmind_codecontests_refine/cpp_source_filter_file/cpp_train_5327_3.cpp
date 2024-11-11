#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void cpuTime() {
  cerr << "cpu time : " << double(clock()) / CLOCKS_PER_SEC << "\n";
  return;
}
using ll = long long;
using ull = unsigned long long;
using F = float;
using D = double;
using vi = vector<int>;
using pii = pair<int, int>;
void solve() {
  int n = 0, s = 0, t = 0;
  cin >> n >> s >> t;
  if (n <= s && n <= t) {
    cout << "1\n";
    return;
  }
  cout << min(s, t) + 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cpuTime();
  return 0;
}
