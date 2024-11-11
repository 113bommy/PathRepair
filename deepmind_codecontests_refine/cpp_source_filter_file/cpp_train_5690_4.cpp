#include <bits/stdc++.h>
using namespace std;
int N, M, S;
vector<int> adj[100010], grp[200010];
queue<int> q;
int vis[200010], par[200010];
void bfs() {
  memset(par, -1, sizeof(par));
  q.push(2 * S);
  vis[2 * S] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < grp[u].size(); i++) {
      int v = grp[u][i];
      if (!vis[v]) {
        q.push(v);
        par[v] = u;
        vis[v] = 1;
      }
    }
  }
}
int tin[100010], tout[100010], timer;
bool dfs(int u) {
  tin[u] = timer++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (tin[v] != -1) {
      if (tout[u] == -1 && tin[v] < tin[u]) return true;
      continue;
    }
    if (dfs(v)) return true;
  }
  tout[u] = timer;
  return false;
}
vector<int> sol;
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    int c;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      int d;
      scanf("%d", &d);
      d--;
      adj[i].push_back(d);
    }
  }
  scanf("%d", &S);
  S--;
  for (int u = 0; u < N; u++) {
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      grp[2 * u].push_back(2 * v + 1);
      grp[2 * u + 1].push_back(2 * v);
    }
  }
  bfs();
  for (int i = 0; i < N; i++)
    if (adj[i].size() == 0 && vis[2 * i + 1]) {
      int u = 2 * i + 1;
      sol.push_back(u / 2);
      while (1) {
        u = par[u];
        sol.push_back(u / 2);
        if (u == 2 * S) break;
      }
      printf("Win\n");
      for (int j = (int)sol.size() - 1; j >= 0; j--) {
        printf("%d ", sol[j] + 1);
      }
      return 0;
    }
  memset(tin, -1, sizeof(tin));
  memset(tout, -1, sizeof(tout));
  if (dfs(S)) {
    printf("Draw");
  } else
    printf("Lose");
}
