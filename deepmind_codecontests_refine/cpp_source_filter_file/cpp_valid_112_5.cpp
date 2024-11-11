#include <bits/stdc++.h>
using namespace std;
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
long long inf = 2e18;
char nl = '\n';
long long mod = 1e9 + 7;
bool can = true;
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  long long p1 = a - 1, p2 = b - 1, p3 = c - 1;
  if (p1 + p2 + p3 < m) can = false;
  if (p1 + p2 + p3 >= m) {
    vector<long long> t = {a, b, c};
    sort((t).begin(), (t).end());
    long long sum = a + b;
    t[2] -= (m + 1);
    if (t[2] > t[1] + t[2] + 1) {
      can = false;
    }
  }
  cout << (can ? "YES" : "NO") << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto begin = std::chrono::high_resolution_clock::now();
  long long t = 1;
  cin >> t;
  while (t--) {
    can = true;
    solve();
  }
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
  return 0;
}
