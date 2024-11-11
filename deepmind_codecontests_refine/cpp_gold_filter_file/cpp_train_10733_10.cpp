#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
static int T, N, V, X[MAXN], Y[MAXN];
static vector<int> edge[MAXN];
inline int find_node(int root) {
  static int vis[MAXN];
  queue<int> Q;
  memset(vis, 0, sizeof vis);
  Q.push(root);
  vis[root] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (X[u]) return u;
    vis[u] = 1;
    for (int v : edge[u])
      if (!vis[v]) Q.push(v);
  }
  return -1;
}
inline int interact(char op, int u) {
  int response;
  printf("%c %d\n", op, u);
  fflush(stdout);
  scanf("%d", &response);
  return response;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      edge[i] = vector<int>();
      X[i] = Y[i] = 0;
    }
    for (int i = 0, u, v; i < N - 1; i++) {
      scanf("%d%d", &u, &v);
      edge[u].emplace_back(v);
      edge[v].emplace_back(u);
    }
    int tmp;
    scanf("%d", &tmp);
    for (int i = 0, x; i < tmp; i++) {
      scanf("%d", &x);
      X[x] = 1;
    }
    scanf("%d", &tmp);
    for (int i = 0, x; i < tmp; i++) {
      scanf("%d", &x);
      Y[V = x] = 1;
    }
    int u = find_node(interact('B', V));
    printf("C %d\n", Y[interact('A', u)] ? u : -1);
    fflush(stdout);
  }
  return 0;
}
