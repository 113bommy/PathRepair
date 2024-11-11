#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
using namespace std;
int n, m, k;
vector<pair<int, int> > e[maxn];
int dis[maxn];
vector<int> pre[maxn];
vector<string> ans;
string str;
void bfs() {
  memset(dis, inf, sizeof(dis));
  queue<int> q;
  dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (pair<int, int> x : e[t]) {
      if (dis[x.first] > dis[t] + 1) {
        dis[x.first] = dis[t] + 1;
        q.push(x.first);
      }
    }
  }
}
void dfs(int p) {
  if (ans.size() >= k) return;
  if (p > n) {
    ans.push_back(str);
    return;
  }
  for (int x : pre[p]) {
    str[x] = '1';
    dfs(p + 1);
    str[x] = '0';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) str += '0';
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(make_pair(v, i));
    e[v].push_back(make_pair(u, i));
  }
  bfs();
  for (int i = 2; i <= n; i++) {
    for (pair<int, int> x : e[i]) {
      if (dis[x.first] + 1 == dis[i]) pre[i].push_back(x.second);
    }
  }
  dfs(2);
  cout << ans.size() << endl;
  for (string x : ans) {
    cout << x << endl;
  }
  return 0;
}
