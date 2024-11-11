#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)2e5 + 3;
const int infint = (int)1e9;
const long long inf = (long long)1e18;
const int MAXN = 530;
vector<int> G[MAXN];
int cap[MAXN][MAXN], cost[MAXN][MAXN], n, d[MAXN], p[MAXN], in[MAXN],
    maicap[MAXN][MAXN], a[MAXN], par[MAXN], visited[MAXN], cur[MAXN];
bool relax(int &u, int &v, int &w) {
  if (d[v] > d[u] + w) {
    p[v] = u;
    d[v] = d[u] + w;
    return 1;
  }
  return 0;
}
void spfa(int src) {
  for (int i = 0; i < MAXN; i++) d[i] = infint, p[i] = -1, in[i] = 0;
  d[src] = 0;
  queue<int> q;
  q.push(src);
  in[src] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    in[u] = false;
    for (auto v : G[u])
      if (cap[u][v] > 0)
        if (relax(u, v, cost[u][v]) && !in[v]) {
          in[v] = 1;
          q.push(v);
        }
  }
}
int mcmf(int K, int src, int sink) {
  int cost = 0, flow = 0;
  while (true) {
    spfa(src);
    if (d[sink] == infint) break;
    int f = K - flow, cur = sink;
    while (cur != src) {
      f = min(f, cap[p[cur]][cur]);
      cur = p[cur];
    }
    flow += f, cost += f * d[sink];
    cur = sink;
    while (cur != src) {
      cap[p[cur]][cur] -= f;
      cap[cur][p[cur]] += f;
      cur = p[cur];
    }
  }
  if (flow < K)
    return -1;
  else
    return cost;
}
int setbit(int x) {
  int ans = 0;
  while (x) {
    ans += x % 2;
    x /= 2;
  }
  return ans;
}
void dfs(int u, int vari) {
  par[u] = vari;
  visited[u] = 1;
  for (auto v : G[u])
    if (!visited[v] && cap[u][v] != maicap[u][v]) dfs(v, vari);
}
string tostr(int x) {
  string p;
  while (x) {
    p += (char)((x % 10) + '0');
    x /= 10;
  }
  reverse(p.begin(), p.end());
  return p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int src = 0;
  for (int i = 1; i <= m + n; i++) {
    G[src].push_back(i);
    G[i].push_back(src);
    cap[src][i] = 1;
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      G[i].push_back(n + m + j);
      G[n + m + j].push_back(i);
      cap[i][n + m + j] = 1;
      cost[i][n + m + j] = setbit(a[j]);
      cost[n + m + j][i] = -cost[i][n + m + j];
    }
  for (int i = m + 1; i <= n + m; i++)
    for (int j = i - m + 1; j <= n; j++) {
      G[i].push_back(n + m + j);
      G[n + m + j].push_back(i);
      cap[i][n + m + j] = 1;
      if (a[i - m] != a[j]) {
        cost[i][n + m + j] = setbit(a[j]);
        cost[n + m + j][i] = -cost[i][n + m + j];
      }
    }
  int sink = n * 2 + m + 1;
  for (int j = 1; j <= n; j++) {
    G[n + m + j].push_back(sink);
    G[sink].push_back(n + m + j);
    cap[n + m + j][sink] = 1;
  }
  for (int i = 0; i <= sink; i++)
    for (int j = 0; j <= sink; j++) maicap[i][j] = cap[i][j];
  visited[src] = 1;
  visited[sink] = 1;
  int t = mcmf(n, src, sink);
  for (int i = 1; i <= n; i++) {
    G[i + m].push_back(m + n + i);
    G[m + n + i].push_back(m + i);
    cap[i + m][m + n + i] = infint;
    cap[m + n + i][i + m] = infint;
  }
  for (int i = 1; i <= m; i++) dfs(i, i);
  memset(cur, -1, sizeof cur);
  vector<string> ans;
  for (int i = 1; i <= n; i++) {
    if (cur[par[i + m + n]] != a[i]) {
      string t;
      t += (char)('a' + par[i + m + n] - 1);
      t += '=';
      t += tostr(a[i]);
      ans.push_back(t);
      cur[par[i + n + m]] = a[i];
    }
    string t = "print(";
    t += (char)('a' + par[i + n + m] - 1);
    t += ')';
    ans.push_back(t);
  }
  cout << ans.size() << " " << t << "\n";
  for (auto u : ans) cout << u << "\n";
}
