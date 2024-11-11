#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, d, a, b, city[maxn], depth[maxn], dist[maxn], father[maxn],
    can_go[maxn];
bool mark_city[maxn], mark[maxn];
vector<int> adj[maxn];
void dfs(int curr, int prev, int d) {
  father[curr] = prev;
  dist[curr] = d;
  for (vector<int>::iterator it = adj[curr].begin(); it != adj[curr].end();
       it++)
    if (*it != prev) dfs(*it, curr, d + 1);
}
int dfs_search(int curr, int prev, int d) {
  int ret = -1;
  if (mark_city[curr]) ret = d;
  for (vector<int>::iterator it = adj[curr].begin(); it != adj[curr].end();
       it++)
    if (*it != prev) ret = max(ret, dfs_search(*it, curr, d + 1));
  return ret;
}
void dfs_mark(int curr, int prev, int pos) {
  if (pos < 0) return;
  mark[curr] = true;
  for (vector<int>::iterator it = adj[curr].begin(); it != adj[curr].end();
       it++)
    if (*it != prev) dfs_mark(*it, curr, pos - 1);
}
int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    scanf("%d", &city[i]);
    city[i]--;
    mark_city[city[i]] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  dfs(city[0], -1, 0);
  int node = -1;
  for (int i = 0; i < m; i++)
    if (node == -1 || dist[node] < dist[city[i]]) node = city[i];
  dfs(node, -1, 0);
  node = -1;
  for (int i = 0; i < m; i++)
    if (node == -1 || dist[node] < dist[city[i]]) node = city[i];
  if (dist[node] > 2 * d) {
    printf("0\n");
    return 0;
  }
  int len = dist[node] / 2;
  for (int i = 0; i < len; i++) node = father[node];
  int idx = 0;
  for (vector<int>::iterator it = adj[node].begin(); it != adj[node].end();
       it++, idx++)
    depth[idx] = dfs_search(*it, node, 1);
  pair<int, int> two_max = make_pair(0, 0);
  for (int i = 0; i < adj[node].size(); i++) {
    if (depth[i] > two_max.first) {
      two_max.second = two_max.first;
      two_max.first = depth[i];
    } else if (depth[i] > two_max.second)
      two_max.second = depth[i];
  }
  for (int i = 0; i < adj[node].size(); i++) {
    if (depth[i] == two_max.first)
      can_go[i] = d - two_max.second - 1;
    else
      can_go[i] = d - two_max.first - 1;
  }
  mark[node] = true;
  idx = 0;
  for (vector<int>::iterator it = adj[node].begin(); it != adj[node].end();
       it++, idx++)
    dfs_mark(*it, node, can_go[idx]);
  int sol = 0;
  for (int i = 0; i < n; i++)
    if (mark[i]) sol++;
  printf("%d\n", sol);
  return 0;
}
