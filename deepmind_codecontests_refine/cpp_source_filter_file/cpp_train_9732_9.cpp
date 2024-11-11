#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int dp[maxN], mark[maxN], par[maxN], ch[maxN];
vector<pair<pair<int, int>, int> > ed;
vector<pair<int, int> > a[maxN];
int vis[maxN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    a[v].push_back(make_pair(u, i));
    a[u].push_back(make_pair(v, i));
    ed.push_back(make_pair(make_pair(v, u), w));
  }
  queue<int> q;
  q.push(0);
  mark[0] = 1;
  par[0] = -1;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto u : a[v]) {
      if (mark[u.first] == 0) {
        mark[u.first] = mark[v] + 1;
        par[u.first] = v;
        ch[u.first] = u.second;
        dp[u.first] = dp[v] + ed[u.second].second;
        q.push(u.first);
      } else if (mark[u.first] == mark[v] + 1 &&
                 dp[u.first] < dp[v] + 1 - ed[u.second].second) {
        par[u.first] = v;
        ch[u.first] = u.second;
        dp[u.first] = dp[v] + ed[u.second].second;
      }
    }
  }
  int x = n - 1;
  while (par[x] > -1) {
    vis[ch[x]] = 1;
    x = par[x];
  }
  vector<pair<pair<int, int>, int> > ans;
  for (int i = 0; i < m; i++)
    if (vis[i] != ed[i].second) ans.push_back(ed[i]), ans.back().second ^= 1;
  cout << ans.size() << endl;
  for (auto u : ans)
    cout << u.first.first + 1 << ' ' << u.first.second + 1 << ' ' << u.second
         << endl;
  return 0;
}
