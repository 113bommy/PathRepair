#include <bits/stdc++.h>
using namespace std;
int par[20005], sz[20005], visit[20005], rev[20005], indeg[20006], hgt[20006];
vector<int> adj[20006];
char S[1006][1006];
int loop;
int find_parent(int x) {
  if (par[x] == x) return x;
  find_parent(par[x]);
}
void unite(int u, int v) {
  u = find_parent(u);
  v = find_parent(v);
  if (u == v) return;
  if (u < v) swap(u, v);
  sz[u] += sz[v];
  par[v] = par[u];
}
void dfs0(int node) {
  if (visit[node]) return;
  visit[node] = 1;
  rev[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    if (visit[adj[node][i]] && rev[adj[node][i]]) loop = 1;
    dfs0(adj[node][i]);
  }
  rev[node] = 0;
}
void dfs(int node) {
  if (visit[node]) return;
  visit[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) dfs(adj[node][i]);
  hgt[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    hgt[node] = max(hgt[node], hgt[adj[node][i]] + 1);
  }
}
int main() {
  int N, M, i, j, k;
  cin >> N >> M;
  for (i = 1; i <= N + M; i++) {
    sz[i] = 1;
    par[i] = i;
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      cin >> S[i][j];
      if (S[i][j] == '=') unite(i, N + j);
    }
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      if (S[i][j] == '>') {
        adj[find_parent(i)].push_back(find_parent(N + j));
        indeg[find_parent(N + j)]++;
      } else if (S[i][j] == '<') {
        adj[find_parent(N + j)].push_back(find_parent(i));
        indeg[find_parent(i)]++;
      }
    }
  }
  for (i = 1; i <= N + M; i++) {
    dfs0(i);
  }
  if (loop) {
    cout << "No\n";
    return 0;
  }
  memset(rev, 0, sizeof(rev));
  memset(visit, 0, sizeof(visit));
  queue<int> Q;
  for (i = 1; i <= N + M; i++) {
    dfs(i);
  }
  cout << "Yes\n";
  for (i = 1; i <= N; i++) cout << hgt[find_parent(i)] << " ";
  cout << endl;
  for (i = 1; i <= M; i++) cout << hgt[find_parent(N + i)] << " ";
  cout << endl;
  return 0;
}
