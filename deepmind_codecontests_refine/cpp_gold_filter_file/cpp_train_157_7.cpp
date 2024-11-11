#include <bits/stdc++.h>
using namespace std;
int A[1000005];
vector<int> G[1000005];
int B[1000005];
vector<int> v;
vector<int> num;
int vis[1000005];
void dfs(int u) {
  vis[u] = 1;
  v.push_back(u);
  for (int i = 0; i < G[u].size(); i++)
    if (!vis[G[u][i]]) dfs(G[u][i]);
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", A + i);
  for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      v.clear();
      num.clear();
      dfs(i);
      for (int i = 0; i < v.size(); i++) num.push_back(A[v[i]]);
      sort(num.rbegin(), num.rend());
      sort(v.begin(), v.end());
      for (int i = v.size() - 1; i >= 0; i--) {
        B[v[i]] = num[i];
      }
    }
  }
  for (int i = 1; i <= N; i++) printf("%d ", B[i]);
  printf("\n");
  return 0;
}
