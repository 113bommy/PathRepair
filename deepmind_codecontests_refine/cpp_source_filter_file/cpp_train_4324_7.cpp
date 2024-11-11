#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};
const int N = 200005;
int n, mx, cnt[N], d, ans;
vector<int> adj[N];
map<pair<int, int>, int> mp;
vector<vector<int>> vv(N);
bool vis[N];
void DFS(int node, int cnt, int cur) {
  vis[node] = true;
  for (int i = 0; i < adj[node].size(); i++) {
    int to = adj[node][i];
    if (!vis[to]) {
      if (cnt == cur) cnt++;
      vv[cnt].push_back(mp[{node, to}]);
      DFS(to, cnt + 1, cur);
      cnt++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    cnt[x]++;
    cnt[y]++;
    adj[x].push_back(y);
    adj[y].push_back(x);
    mp[make_pair(x, y)] = i;
    mp[make_pair(y, x)] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > d) {
      d = cnt[i];
      ans = cnt[i];
      mx = i;
    }
  }
  vis[mx] = true;
  d = 1;
  for (int i = 0; i < adj[mx].size(); i++) {
    int to = adj[mx][i];
    vv[d++].push_back(mp[{mx, to}]);
    DFS(to, 1, d - 1);
  }
  for (int i = ans + 1; i <= 200005; i++) {
    if (vv[i].size() > 0)
      ans = i;
    else
      break;
  }
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    cout << vv[i].size() << " ";
    for (int j = 0; j < vv[i].size(); j++) {
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
