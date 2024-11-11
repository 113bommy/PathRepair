#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e9 + 7;
const ll INF = 1e18 + 5;
map<int, int> mp[N];
set<pair<int, int> > st[N];
int dp[N];
int a[N], b[N], w[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> w[i];
    dp[i] = 1;
    if (!st[a[i]].empty()) {
      auto it = st[a[i]].lower_bound({w[i], 0});
      if (it != st[a[i]].begin()) {
        it--;
        dp[i] = it->second + 1;
      }
    }
    if (!st[b[i]].empty()) {
      auto last = st[b[i]].lower_bound({w[i], 0});
      while (last != st[b[i]].end() && dp[i] >= last->second) {
        st[b[i]].erase(last);
        if (st[b[i]].empty()) break;
        last = st[b[i]].lower_bound({w[i], 0});
      }
      auto it = st[b[i]].lower_bound({w[i], 0});
      if (it != st[b[i]].begin()) {
        it--;
        if (it->second >= dp[i]) {
          continue;
        }
      }
    }
    st[b[i]].insert({w[i], dp[i]});
  }
  cout << *max_element(dp + 1, dp + 1 + m);
  return 0;
}
