#include <bits/stdc++.h>
using namespace std;
struct arc {
  int to, nxt;
} e[300003 << 1];
int p;
int h[300003];
bool part[300003];
void add_edge(int x, int y) {
  e[++p].nxt = h[x];
  e[p].to = y;
  h[x] = p;
}
void dfs(int u) {
  int t = 0;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (part[v] == part[u]) t++;
  }
  if (t > 1) {
    part[u] ^= 1;
    for (int i = h[u]; i; i = e[i].nxt) dfs(e[i].to);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a, b;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    add_edge(a, b);
    add_edge(b, a);
  }
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = 1; i <= n; i++) printf("%d", part[i]);
  return 0;
}
