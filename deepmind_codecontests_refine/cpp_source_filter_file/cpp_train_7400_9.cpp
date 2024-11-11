#include <bits/stdc++.h>
using namespace std;
int n, k;
set<pair<int, int>> S[100010];
struct Queue {
  int k, v;
  friend bool operator<(const Queue &u, const Queue &v) { return u.v > v.v; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    S[y].insert({x, z});
    S[x].insert({y, z});
  }
  priority_queue<Queue> Q;
  for (int i = 1; i <= n; ++i)
    if (S[i].size() == 1) Q.push({i, S[i].begin()->second});
  int ans;
  while (Q.size() > 2 || k < n) {
    int u = Q.top().k, v;
    ans = Q.top().v;
    Q.pop();
    --n;
    v = S[u].begin()->first;
    S[v].erase(S[v].lower_bound({u, 0}));
    if (S[v].size() == 1) Q.push({v, ans + S[v].begin()->second});
  }
  cout << ans << "\n";
  return 0;
}
