#include <bits/stdc++.h>
using namespace std;
int n, m, v[2010], numNode = 1, lab[2010];
vector<int> a[2010], b[2010];
bool isBrid[2010][2010];
int cnt, num[2010], low[2010];
bool visited[2010];
int sumNode[2010], d[2010];
int memo[2010][2010], root;
int ans = 0;
int temp = 0;
void dfs(int u, int p) {
  num[u] = low[u] = ++cnt;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) continue;
    if (num[v]) {
      low[u] = min(low[u], num[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[v]) {
        isBrid[u][v] = isBrid[v][u] = 1;
      }
    }
  }
}
void dfs2(int x) {
  int temp = numNode;
  queue<int> q;
  q.push(x);
  visited[x] = 1;
  int qu = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    lab[u] = temp;
    sumNode[temp]++;
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (visited[v]) continue;
      if (isBrid[u][v]) {
        numNode++;
        b[temp].push_back(numNode);
        b[numNode].push_back(temp);
        dfs2(v);
      } else {
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}
void reset(int u) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < a[u].size(); j++) memo[j][i] = -1;
  }
}
void dfs3(int u, int p) {
  d[u] = 0;
  for (int i = 0; i < b[u].size(); i++) {
    int v = b[u][i];
    if (v == p) continue;
    dfs3(v, u);
    d[u] += d[v];
  }
  temp = temp + sumNode[u] * d[u];
  d[u] += sumNode[u];
}
int solve(int in, int s) {
  if (in == b[root].size()) return s * (n - sumNode[root] - s);
  if (memo[in][s] != -1) return memo[in][s];
  int cur = max(solve(in + 1, s + d[b[root][in]]), solve(in + 1, s));
  return memo[in][s] = cur;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1);
  int add = 0;
  for (int i = 1; i <= numNode; i++) add += sumNode[i] * sumNode[i];
  for (int i = 1; i <= numNode; i++) {
    temp = 0;
    reset(i);
    dfs3(i, 0);
    root = i;
    ans = max(ans, solve(0, 0) + add + temp);
  }
  cout << ans;
}
