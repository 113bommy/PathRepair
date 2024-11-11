#include <bits/stdc++.h>
using namespace std;
int n;
long long wei[300010];
vector<pair<int, long long>> a[300010];
long long val[300010];
bool vis[300010];
int h[300010];
int hei;
long long dfs(int x) {
  if (vis[x]) return -1;
  hei++;
  vis[x] = 1;
  h[x] = hei;
  long long ans = wei[x];
  for (int i = 0; i < a[x].size(); i++) {
    if (!vis[a[x][i].first])
      ans = max(ans, wei[x] + dfs(a[x][i].first) - a[x][i].second);
  }
  val[x] = ans;
  h[x] = hei;
  return ans;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= int(n); i++) {
    long long x;
    cin >> x;
    wei[i] = x;
  }
  for (int i = 0; i < int(n - 1); i++) {
    int x, y;
    long long w;
    cin >> x >> y >> w;
    a[x].push_back(make_pair(y, w));
    a[y].push_back(make_pair(x, w));
  }
  dfs(1);
  long long ans = -1;
  for (int i = 1; i <= int(n); i++) {
    ans = max(ans, val[i]);
    vector<long long> v;
    for (int j = 0; j < a[i].size(); j++) {
      if (h[a[i][j].first] > h[i])
        v.push_back(val[a[i][j].first] - a[i][j].second);
    }
    sort(v.begin(), v.end());
    if (v.size() > 1)
      ans = max(ans, wei[i] + v[v.size() - 1] + v[v.size() - 2]);
  }
  cout << ans << endl;
}
