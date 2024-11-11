#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int MAX = 130000;
vector<int> adj[MAX];
int d[MAX], size[MAX];
bool mark[MAX];
void dfs(int p, int v) {
  size[v] = 0;
  if (mark[v]) size[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (u != p) {
      d[u] = d[v] + 1;
      dfs(v, u);
      size[v] += size[u];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    v--;
    mark[v] = true;
  }
  dfs(-1, 0);
  int v = -1;
  for (int i = 0; i < n; i++)
    if (mark[i] && (v == -1 || d[v] < d[i])) v = i;
  memset(d, 0, sizeof(d));
  dfs(-1, v);
  int sum = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (size[i] > 0 && m - size[i] > 0) sum += 2;
    if (mark[i]) mx = max(mx, d[i]);
  }
  for (int i = 0; i < n; i++)
    if (mark[i] && i < v && d[i] == mx) {
      v = i;
      break;
    }
  cout << v + 1 << "\n" << sum - mx << "\n";
  return 0;
}
