#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m;
    b /= 2;
    a = ((a % m) * (a % m)) % m;
  }
  return ans % m;
}
vector<pair<int, int> > g[500005];
map<pair<int, int>, int> mm;
vector<pair<int, pair<int, int> > > ed;
int d[500005];
int ok[500005];
queue<int> q;
int par[500005];
bool vis[500005];
vector<pair<int, pair<int, int> > > ans;
int main() {
  int n, m;
  cin >> n >> m;
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
    mm[make_pair(x, y)] = i;
    mm[make_pair(y, x)] = i;
    ed.push_back(make_pair(z, make_pair(x, y)));
  }
  for (int i = 1; i <= n; i++) d[i] = 500005;
  d[1] = 0;
  ok[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first;
      if (d[v] > (d[u] + 1)) {
        d[v] = d[u] + 1;
        if (g[u][i].second == 1)
          ok[v] = ok[u] + 1;
        else
          ok[v] = ok[u];
        par[v] = u;
        q.push(v);
      } else if (d[v] == (d[u] + 1)) {
        if (g[u][i].second == 1) {
          if (ok[u] + 1 > ok[v]) {
            ok[v] = ok[u] + 1;
            q.push(v);
            par[u] = v;
          }
        } else {
          if (ok[u] > ok[v]) {
            ok[v] = ok[u];
            q.push(v);
            par[v] = u;
          }
        }
      }
    }
  }
  int node = n;
  while (node != 1) {
    int path = mm[make_pair(node, par[node])];
    vis[path] = 1;
    node = par[node];
  }
  for (int i = 1; i <= m; i++) {
    if (vis[i]) {
      if (ed[i - 1].first == 0)
        ans.push_back(make_pair(ed[i - 1].second.first,
                                make_pair(ed[i - 1].second.second, 1)));
    }
    if (!vis[i]) {
      if (ed[i - 1].first == 1) {
        ans.push_back(make_pair(ed[i - 1].second.first,
                                make_pair(ed[i - 1].second.second, 0)));
      }
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second.first << " "
         << ans[i].second.second << "\n";
  }
}
