#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<int> ans;
vector<pii> edgs;
int n, m;
bool marked[int(1e6)];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ans.reserve(int(1e6));
  int tsk;
  cin >> tsk;
  while (tsk--) {
    cin >> n >> m;
    edgs.resize(m);
    for (auto &i : edgs) cin >> i.first >> i.second;
    for (int i = 0; i < m; ++i)
      if (!marked[edgs[i].first] && !marked[edgs[i].second]) {
        marked[edgs[i].first] = marked[edgs[i].second] = true;
        ans.push_back(i);
      }
    if (ans.size() >= n) {
      ans.resize(n);
      cout << "Matching\n";
      for (auto i : ans) cout << i + 1 << ' ';
      cout << '\n';
    } else {
      ans.clear();
      for (int i = 1; i <= 3 * n; ++i)
        if (!marked[i]) ans.push_back(i);
      if (ans.size() > n) ans.resize(n);
      cout << "IndSet\n";
      for (auto i : ans) cout << i << ' ';
      cout << '\n';
    }
    ans.clear();
    for (int i = 1; i <= n; ++i) marked[i] = true;
  }
  return 0;
}
