#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[100005];
bool used[100005];
bool book[2 * 100005];
int ans;
int gcd(int x, int y) { return (y == 0) ? x : gcd(y, x % y); }
struct Edge {
  int from, to, cost;
};
vector<int> v[100005];
vector<Edge> edges;
void addedge(int from, int to) {
  edges.push_back(Edge{from, to, 1});
  edges.push_back(Edge{to, from, -1});
  int sz = edges.size();
  v[from].push_back(sz - 2);
  v[to].push_back(sz - 1);
}
void dfs(int now, int d) {
  if (used[now]) {
    if (d != dp[now]) ans = gcd(abs(d - dp[now]), ans);
    return;
  }
  used[now] = 1;
  dp[now] = d;
  for (int i = 0; i < v[now].size(); i++) {
    if (!book[v[now][i]]) {
      book[v[now][i]] = 1;
      Edge e = edges[v[now][i]];
      dfs(e.to, d + e.cost);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) dfs(i, 0);
  }
  if (ans == 0) ans = n;
  printf("%d", ans);
  return 0;
}
