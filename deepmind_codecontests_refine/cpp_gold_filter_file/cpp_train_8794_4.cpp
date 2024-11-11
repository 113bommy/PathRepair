#include <bits/stdc++.h>
using namespace std;
const int N = 800005;
int Head[N], Next[N], Adj[N], tot = 1, deg[N];
void addedge(int u, int v) {
  Next[++tot] = Head[u], Head[u] = tot, Adj[tot] = v;
  Next[++tot] = Head[v], Head[v] = tot, Adj[tot] = u;
  deg[u]++, deg[v]++;
}
int used[N];
void dfs(int x) {
  for (int &e = Head[x]; e; e = Next[e])
    if (!used[e >> 1]) used[e >> 1] = (x <= 200000) + 1, dfs(Adj[e]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y + 200000);
  }
  for (int i = 1; i <= 400000; i++)
    if (deg[i] & 1) addedge(0, i);
  for (int i = 1; i <= 400000; i++) dfs(i);
  for (int i = 1; i <= n; i++)
    if (used[i] == 1)
      putchar('r');
    else
      putchar('b');
  return 0;
}
