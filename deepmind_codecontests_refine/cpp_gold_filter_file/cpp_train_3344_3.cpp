#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 2e5 + 5;
const double pi = acos(-1);
long long n, m, indeg[N], ans1, ans2, mn = 1e9;
vector<vector<pair<long long, long long>>> v(N);
vector<pair<pair<long long, long long>, long long>> ans;
void dfs(int node) {
  if (v[node].size() == 0) {
    ans2 = node;
    return;
  }
  for (int i = 0; i < v[node].size(); i++) {
    mn = min(mn, v[node][i].second);
    dfs(v[node][i].first);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    v[b].push_back({a, c});
    indeg[a]++;
  }
  for (int i = 1; i <= n; i++) {
    ans1 = i, mn = 1e9;
    if (indeg[i] == 0) {
      dfs(i);
      if (mn == 1e9) continue;
      ans.push_back({{ans2, ans1}, mn});
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first.first << " " << ans[i].first.second << " "
         << ans[i].second << endl;
  return 0;
}
