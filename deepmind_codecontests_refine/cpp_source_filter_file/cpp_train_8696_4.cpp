#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int> > > v(100010);
long long int visited[100010] = {0}, weight[100010], ans = 0;
long long int remove(long long int i) {
  visited[i] = 1;
  long long int count = 0;
  for (long long int j = 0; j < v[i].size(); ++j) {
    if (!visited[v[i][j].first]) count = 1 + remove(v[i][j].first);
  }
  return count;
}
void dfs(long long int i, long long int prev) {
  visited[i] = 1;
  if (prev > weight[i]) {
    long long int temp = remove(i);
    ans += temp + 1;
    return;
  }
  for (long long int j = 0; j < v[i].size(); ++j) {
    if (!visited[v[i][j].first]) {
      if (v[i][j].second + prev < 0)
        dfs(v[i][j].first, 0);
      else
        dfs(v[i][j].first, prev + v[i][j].second);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, i, j, m, x, y;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> weight[i];
  for (i = 1; i < n; ++i) {
    cin >> x >> y;
    v[i + 1].push_back({x, y});
    v[x].push_back({i + 1, y});
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
