#include <bits/stdc++.h>
using namespace std;
bool com(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.second == p2.second) return p1.first > p2.first;
  return p1.second > p2.second;
}
void solve() {
  long long n = 0, m = 0;
  cin >> n >> m;
  vector<long long> v;
  long long tot = 0;
  for (int i = 1; i <= m; i++) {
    long long mask = (i & -i);
    if (tot + mask <= n) {
      tot += mask;
      v.push_back(i);
    }
    if (tot == n) break;
  }
  if (tot == n) {
    cout << v.size() << "\n";
    for (auto i : v) cout << i << " ";
  } else {
    cout << -1 << "\n";
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
