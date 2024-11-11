#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adjlist;
vector<pair<int, int> > Queries;
long long up[100001], down[100001];
long long downnodes[100001];
int kthparent[100001][30];
int depthofnode[100001];
int n, m;
pair<int, long long> dfs(int node, int parent, int depth) {
  kthparent[node][0] = parent;
  depthofnode[node] = depth;
  downnodes[node] = 1;
  for (int i = 0; i < adjlist[node].size(); i++) {
    if (adjlist[node][i] == parent) continue;
    pair<int, long long> cur = dfs(adjlist[node][i], node, depth + 1);
    down[node] += (long long)(cur.first + cur.second);
    downnodes[node] += cur.first;
  }
  return make_pair(downnodes[node], down[node]);
}
void calcup(int node, int parent) {
  up[node] = up[parent] + n - downnodes[node] + down[parent] - down[node] -
             downnodes[node];
  up[1] = 0;
  for (int i = 0; i < adjlist[node].size(); i++)
    if (adjlist[node][i] != parent) calcup(adjlist[node][i], node);
  return;
}
int LCA(int a, int b) {
  if (depthofnode[b] > depthofnode[a]) swap(a, b);
  int diff = depthofnode[a] - depthofnode[b];
  for (int i = 29; i >= 0; i--)
    if (diff & (1 << i)) a = kthparent[a][i];
  if (a == b) return a;
  for (int i = 29; i >= 0; i--)
    if (kthparent[a][i] != kthparent[b][i]) {
      a = kthparent[a][i];
      b = kthparent[b][i];
    }
  return kthparent[a][0];
}
int get_kth(int a, int dep) {
  for (int i = 29; i >= 0; i--)
    if (dep & (1 << i)) a = kthparent[a][i];
  return a;
}
int main() {
  scanf("%d%d", &n, &m);
  adjlist.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Queries.push_back(make_pair(a, b));
  }
  dfs(1, 1, 1);
  calcup(1, 1);
  for (int i = 1; i <= 29; i++)
    for (int j = 1; j <= n; j++)
      kthparent[j][i] = kthparent[kthparent[j][i - 1]][i - 1];
  for (int i = 0; i < m; i++) {
    double ans = 0;
    int a = Queries[i].first, b = Queries[i].second;
    int c = LCA(a, b);
    int length =
        depthofnode[a] + depthofnode[b] - depthofnode[c] - depthofnode[c];
    if (c != a && c != b) {
      double prob1 = (double)1 / downnodes[a], prob2 = 1.0 / downnodes[b];
      ans += (double)(down[a] * prob1 + down[b] * prob2) + length + 1.0;
      printf("%.10lf\n", ans);
    } else {
      if (depthofnode[b] > depthofnode[a]) swap(b, a);
      int tmnode = get_kth(a, depthofnode[a] - depthofnode[b] - 1);
      double prob1 = (double)1 / downnodes[a],
             prob2 = 1.0 / ((double)n - downnodes[tmnode]);
      ans += (double)(down[a]) * prob1 +
             (down[b] + up[b] - down[tmnode] - downnodes[tmnode]) * prob2 +
             length + 1;
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
