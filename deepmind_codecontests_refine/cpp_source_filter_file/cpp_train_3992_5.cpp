#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100, inf = 1000000000, mod = 1000003;
vector<int> adj[maxn], aj[maxn], height;
int p[maxn], h[maxn], par[maxn], mx[maxn], dp[maxn][20], t[20], s[maxn];
int find(int a);
void un(int a, int b) { p[find(a)] = find(b); }
int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
void dfs(int x, int l) {
  h[x] = (l != -1) ? h[l] + 1 : 0;
  par[x] = l;
  for (int i = 0; i < adj[x].size(); i++) {
    int next = adj[x][i];
    if (h[next] == -1)
      dfs(next, x);
    else if (next != l) {
      int w = find(x);
      while (h[w] > h[next] && find(w) != find(next)) {
        un(find(w), find(next));
        w = find(par[w]);
      }
    }
  }
}
void DFS(int x, int l) {
  h[x] = (l != -1) ? h[l] + 1 : 0;
  par[x] = l;
  s[x] = height.size();
  height.push_back(h[x]);
  for (int i = 0; i < aj[x].size(); i++) {
    int next = aj[x][i];
    if (h[next] == -1) {
      DFS(next, x);
      height.push_back(h[x]);
    }
  }
}
int lca(int a, int b) {
  if (a > b) swap(a, b);
  return min(dp[a][mx[b - a]], dp[b - (1 << mx[b - a])][mx[b - a]]);
}
int main() {
  mx[1] = 1;
  for (int i = 2; i < maxn; i++)
    mx[i] = ((2 << mx[i - 1]) <= i) ? mx[i - 1] + 1 : mx[i - 1];
  for (int i = 0; i < maxn; i++) p[i] = i;
  fill(s, s + maxn, -1);
  fill(h, h + maxn, -1);
  fill(par, par + maxn, -1);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < adj[i].size(); j++)
      if (find(i) < find(adj[i][j])) {
        aj[find(i)].push_back(find(adj[i][j]));
        aj[find(adj[i][j])].push_back(find(i));
      }
  fill(h, h + maxn, -1);
  DFS(find(0), -1);
  for (int i = 0; i < height.size(); i++) dp[i][0] = height[i];
  for (int i = height.size() - 1; i >= 0; i--)
    for (int j = 1; i + (1 << j) <= height.size(); j++)
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
  int k;
  cin >> k;
  while (k--) {
    cin >> a >> b;
    a--;
    b--;
    int p = lca(s[find(a)], s[find(b)]);
    cout << h[find(a)] + h[find(b)] - 2 * p << endl;
  }
  return 0;
}
