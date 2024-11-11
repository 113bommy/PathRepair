#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m, w[N], c[N], u[N], v[N], p[N], e[N], S;
vector<int> sol;
vector<pair<int, int> > g[N];
int dep[N];
pair<int, int> par[N], dp[N][18];
bool vis[N];
inline bool comp(const int &a, const int &b) { return w[a] < w[b]; }
int find(int x) {
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}
void DFS(int v) {
  for (int i = 0; i < (int)g[v].size(); ++i) {
    int u = g[v][i].first;
    if (u != par[v].first) {
      par[u] = make_pair(v, g[v][i].second);
      dep[u] = dep[v] + 1;
      DFS(u);
    }
  }
}
int LCA(int u, int v) {
  if (dep[v] < dep[u]) swap(u, v);
  int log = 0;
  while ((1 << log) <= dep[v]) ++log;
  --log;
  int res = -1;
  for (int i = log; i >= 0; --i)
    if (dep[v] - (1 << i) >= dep[u]) {
      if (res == -1 || w[dp[v][i].second] > w[res]) res = dp[v][i].second;
      v = dp[v][i].first;
    }
  if (u == v) return res;
  for (int i = log; i >= 0; --i)
    if (dp[u][i].first != dp[v][i].first) {
      if (res == -1 || w[dp[u][i].second] > w[res]) res = dp[u][i].second;
      if (res == -1 || w[dp[v][i].second] > w[res]) res = dp[v][i].second;
      u = dp[u][i].first;
      v = dp[v][i].first;
    }
  if (res == -1 || w[par[u].second] > w[res]) res = par[u].second;
  if (res == -1 || w[par[v].second] > w[res]) res = par[v].second;
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d", &w[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &c[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    --u[i], --v[i];
    e[i] = i;
  }
  scanf("%d", &S);
  sort(e, e + m, comp);
  for (int i = 0; i < n; ++i) p[i] = i;
  int comp = n;
  for (int i = 0; i < m && comp != 1; ++i) {
    int a = find(u[e[i]]);
    int b = find(v[e[i]]);
    if (a != b) {
      p[a] = b;
      sol.push_back(e[i]);
      vis[e[i]] = true;
      --comp;
    }
  }
  pair<int, int> mn(2e9, 2e9);
  long long sum = 0;
  for (int i = 0; i < (int)sol.size(); ++i) {
    int a = u[sol[i]], b = v[sol[i]];
    g[a].push_back(make_pair(b, sol[i]));
    g[b].push_back(make_pair(a, sol[i]));
    int cost = c[sol[i]];
    if (cost < mn.first) {
      mn.second = mn.first;
      mn.first = cost;
    } else if (cost < mn.second)
      mn.second = cost;
    sum += w[sol[i]];
  }
  par[0] = make_pair(-1, -1);
  DFS(0);
  for (int i = 0; i < n; ++i) dp[i][0] = par[i];
  for (int j = 1; (1 << j) < n; ++j)
    for (int i = 0; i < n; ++i)
      if (dp[i][j - 1].first != -1) {
        dp[i][j].first = dp[dp[i][j - 1].first][j - 1].first;
        if (w[dp[i][j - 1].second] > w[dp[dp[i][j - 1].first][j - 1].second])
          dp[i][j].second = dp[i][j - 1].second;
        else
          dp[i][j].second = dp[dp[i][j - 1].first][j - 1].second;
      } else
        dp[i][j] = make_pair(-1, -1);
  pair<int, int> add(-1, -1);
  long long best = sum - S / mn.first;
  for (int i = 0; i < m; ++i) {
    if (vis[i]) continue;
    long long nsum = sum;
    int at = LCA(u[i], v[i]), d;
    nsum -= w[at];
    nsum += w[i];
    if (c[i] < mn.first || c[i] < mn.second)
      d = c[i];
    else if (w[at] != mn.first)
      d = mn.first;
    else
      d = mn.second;
    nsum -= S / d;
    if (nsum < best) {
      best = nsum;
      add = make_pair(at, i);
    }
  }
  if (add.first != -1) {
    for (int i = 0; i < (int)sol.size(); ++i)
      if (sol[i] == add.first) {
        sol[i] = add.second;
        break;
      }
  }
  int ch = -1;
  for (int i = 0; i < (int)sol.size(); ++i)
    if (ch == -1 || c[sol[i]] < c[ch]) ch = i;
  w[sol[ch]] -= S / c[sol[ch]];
  printf("%lld\n", best);
  for (int i = 0; i < (int)sol.size(); ++i)
    printf("%d %d\n", sol[i] + 1, w[sol[i]]);
  return 0;
}
