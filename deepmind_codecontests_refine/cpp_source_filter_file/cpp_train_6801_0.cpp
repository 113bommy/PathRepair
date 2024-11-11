#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[100010];
vector<int> adj[100010], radj[100010];
int vis[100010], ans[100010];
queue<int> q;
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  for (int i = 0; i < N; i++) ans[i] = 1;
  for (int i = 0; i < N; i++)
    if (A[i] == 1) {
      q.push(i);
      vis[i] = 1;
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!vis[v]) {
        q.push(v);
        vis[v] = 1;
      }
    }
  }
  for (int i = 0; i < N; i++) ans[i] &= vis[i];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < N; i++)
    if (A[i] == 2) {
      q.push(i);
      vis[i] = 1;
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (A[u] == 1) continue;
    for (int i = 0; i < radj[u].size(); i++) {
      int v = radj[u][i];
      if (!vis[i]) {
        q.push(v);
        vis[v] = 1;
      }
    }
  }
  for (int i = 0; i < N; i++) ans[i] &= vis[i];
  for (int i = 0; i < N; i++) {
    printf("%d\n", ans[i]);
  }
}
