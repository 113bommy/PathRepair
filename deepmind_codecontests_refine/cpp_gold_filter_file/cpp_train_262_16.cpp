#include <bits/stdc++.h>
using namespace std;
int sz[400010];
void dfs(int u, int par, vector<vector<int> >& adj) {
  sz[u] = 1;
  for (auto it : adj[u])
    if (it != par) {
      dfs(it, u, adj);
      sz[u] += sz[it];
    }
}
int furthest_node;
void dfs_centroid(int u, int par, vector<vector<int> >& adj, int N) {
  bool flg = true;
  for (auto it : adj[u])
    if (it != par) {
      dfs_centroid(it, u, adj, N);
      if (sz[it] > N / 2) flg = false;
    }
  if (N - sz[u] > N / 2) flg = false;
  if (flg) furthest_node = u;
}
int firstCentroid(vector<vector<int> >& adj, int N) {
  dfs(1, -1, adj);
  dfs_centroid(1, -1, adj, N);
  return furthest_node;
}
int max_sz[] = {-1, -1}, max_e;
int res[400010];
void dfs_final(int u, int par, int e, vector<vector<int> >& adj, int N) {
  if (sz[u] == N || sz[e] == N - (N / 2))
    res[u] = true;
  else if (e == max_e) {
    res[u] = (N - sz[u] - max_sz[1] <= N / 2);
  } else {
    res[u] = (N - sz[u] - max_sz[0] <= N / 2);
  }
  for (auto it : adj[u])
    if (it != par) dfs_final(it, u, (e == -1 ? it : e), adj, N);
}
int main() {
  int N;
  scanf("%d", &N);
  vector<vector<int> > adj(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    adj[first].push_back(second), adj[second].push_back(first);
  }
  int root = firstCentroid(adj, N);
  dfs(root, -1, adj);
  for (auto it : adj[root]) {
    if (sz[it] > max_sz[0])
      max_sz[1] = max_sz[0], max_sz[0] = sz[it], max_e = it;
    else if (sz[it] > max_sz[1])
      max_sz[1] = sz[it];
  }
  dfs_final(root, -1, -1, adj, N);
  for (int i = 1; i < N + 1; ++i) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
