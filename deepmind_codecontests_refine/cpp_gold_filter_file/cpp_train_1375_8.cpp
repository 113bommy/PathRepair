#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n), sv(n);
  vector<vector<int>> g(31, vector<int>(n));
  for (int j = 0; j < n; j++) {
    int x;
    cin >> x;
    sv[j] = x;
    int cnt = 0;
    for (int i = 29; i >= 0; i--) {
      cnt += (x >> i) & 1;
      g[i][j] = ((x >> i) & 1) ? -1 : 1;
    }
    v[j] = cnt;
  }
  map<vector<int>, int> d;
  for (int mask = 0; mask < (1 << 15); mask++) {
    vector<int> curSum(n);
    for (int i = 0; i < 15; i++) {
      if ((mask >> i) & 1) {
        for (int j = 0; j < n; j++) {
          curSum[j] += g[i][j];
        }
      }
    }
    d[curSum] = mask;
  }
  for (int mask = 0; mask < (1 << 15); mask++) {
    vector<int> curSum(n);
    for (int i = 0; i < 15; i++) {
      if ((mask >> i) & 1) {
        for (int j = 0; j < n; j++) {
          curSum[j] += g[i + 15][j];
        }
      }
    }
    for (int t = 0; t <= 30; t++) {
      vector<int> needSum(n);
      for (int i = 0; i < n; i++) {
        needSum[i] = (t - (v[i] + curSum[i]));
      }
      if (d.count(needSum)) {
        ll ans = (mask << 15) | d[needSum];
        cout << ans;
        return 0;
      }
    }
  }
  cout << -1;
}
