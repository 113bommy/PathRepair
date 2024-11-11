#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> pos[2];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x & 1].push_back(i);
  }
  if (abs((int)pos[0].size() - (int)pos[1].size()) > 1)
    cout << -1 << '\n';
  else {
    long long mn = 1e9;
    if ((int)pos[0].size() - (int)pos[1].size() >= 0) {
      long long cur = 0;
      for (int i = 0; i < n; i++) {
        cur += abs(pos[i & 1][i / 2] - i);
      }
      cur /= 2;
      mn = min(mn, cur);
    }
    if ((int)pos[1].size() - (int)pos[0].size() >= 0) {
      long long cur = 0;
      for (int i = 0; i < n; i++) {
        cur += abs(pos[~i & 1][i / 2] - i);
      }
      cur /= 2;
      mn = min(mn, cur);
    }
    cout << mn << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
