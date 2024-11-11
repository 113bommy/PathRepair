#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
vector<vector<long long> > g;
vector<long long> vis, edge, head;
long long fedge(long long v) {
  if (edge[v] == v)
    return v;
  else
    edge[v] = fedge(edge[v]);
  return edge[v];
}
long long fhead(long long v) {
  if (head[v] == v)
    return v;
  else
    head[v] = fedge(head[v]);
  return head[v];
}
void dfs(long long v) {
  cout << v + 1 << " ";
  vis[v] = 1;
  for (long long i = 0; i < g[v].size(); i++) {
    if (vis[g[v][i]] == 0) dfs(g[v][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  g.resize(n);
  vis.resize(n, 0);
  edge.resize(n);
  head.resize(n);
  for (long long i = 0; i < n; i++) a[i] = 0, edge[i] = i, head[i] = i;
  long long b, c;
  for (long long i = 0; i < n - 1; i++) {
    cin >> b >> c;
    fhead(c - 1);
    fedge(b - 1);
    g[edge[b - 1]].push_back(head[c - 1]);
    a[head[c - 1]]++;
    edge[edge[b - 1]] = edge[c - 1];
    head[head[c - 1]] = head[b - 1];
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) dfs(i);
  }
  return 0;
}
