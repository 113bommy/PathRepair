#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vector<int> both, alice, bob;
    for (int i = 0; i < n; ++i) {
      int t, a, b;
      cin >> t >> a >> b;
      if (a && b)
        both.push_back(t);
      else if (a)
        alice.push_back(t);
      else if (b)
        bob.push_back(t);
    }
    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    vector<int> asum(alice.size() + 1);
    for (int i = 0; i < alice.size(); ++i) {
      asum[1 + i] = asum[i] + alice[i];
    }
    vector<int> bsum(bob.size() + 1);
    for (int i = 0; i < bob.size(); ++i) {
      bsum[1 + i] = bsum[i] + bob[i];
    }
    const int INF = 2e9 + 10;
    int res = INF;
    for (int i = 0, csum = 0; i <= min<int>(k, both.size()); ++i) {
      if (alice.size() + i >= k && bob.size() + i >= k) {
        int cur = asum[k - i] + bsum[k - i] + csum;
        res = min(res, cur);
      }
      if (i < both.size()) {
        csum += both[i];
      }
    }
    cout << (res == INF ? -1 : res) << "\n";
  }
}
