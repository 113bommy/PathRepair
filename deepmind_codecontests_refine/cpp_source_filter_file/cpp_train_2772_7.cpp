#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100, M = 2e5 + 100, MOD = 1e9 + 7, MAXN = 1e5 + 10;
const int inf = 2e9 + 10;
long long ps[N], point[N], dp[N];
int mark[N], mark1[N], mark2[N], mark3[N];
vector<pair<int, int> > v[N], vp[N];
vector<pair<int, int> > adj[N];
vector<int> tp;
int cnt = 0;
long long calc(long long u) {
  int l = 0, h = 100000;
  while (h - l > 1) {
    int m = (l + h) / 2;
    if (1ll * (m) * (m + 1) / 2 > u)
      h = m;
    else
      l = m;
  }
  return 1ll * (l + 1) * u - 1ll * ps[l];
}
void top_sort(int u) {
  mark[u] = 1;
  for (int i = 0; i < (int)v[u].size(); i++) {
    if (mark[v[u][i].first] != 1) top_sort(v[u][i].first);
  }
  tp.push_back(u);
}
void SCC(int u) {
  mark1[u] = cnt;
  for (int i = 0; i < (int)vp[u].size(); i++) {
    if (mark1[vp[u][i].first] == 0) {
      SCC(vp[u][i].first);
    }
  }
}
void dfs(int u) {
  mark3[u] = 1;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    if (!mark3[adj[u][i].first]) dfs(adj[u][i].first);
    dp[u] = max(dp[u], dp[adj[u][i].first] + adj[u][i].second);
  }
  dp[u] += point[u];
}
int u1[N], v1[N], w1[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 1e5 + 1; i++) {
    ps[i] = ps[i - 1] + 1ll * i * (i + 1) / 2;
  }
  int n, m, s;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v[x].push_back(make_pair(y, z));
    vp[y].push_back(make_pair(x, z));
    u1[i] = x;
    v1[i] = y;
    w1[i] = z;
  }
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (mark[i] == 0) {
      top_sort(i);
    }
  }
  reverse(tp.begin(), tp.end());
  for (int i = 0; i < (int)tp.size(); i++) {
    if (mark1[tp[i]] == 0) {
      cnt++;
      SCC(tp[i]);
    }
  }
  for (int i = 0; i < m; i++) {
    if (mark1[u1[i]] == mark1[v1[i]]) point[mark1[u1[i]]] += calc(w1[i]);
  }
  for (int i = 0; i < m; i++) {
    if (mark1[u1[i]] != mark1[v1[i]])
      adj[mark1[u1[i]]].push_back(make_pair(v1[i], w1[i]));
  }
  dfs(mark1[s]);
  cout << dp[mark1[s]] << endl;
  return 0;
}
