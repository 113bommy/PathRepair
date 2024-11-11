#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct Edge {
  int nxt, to;
} e[N * 4 + 5];
int hd[N * 2 + 5], cnt = 1;
inline void add(int u, int v) { e[++cnt] = {hd[u], v}, hd[u] = cnt; }
int deg[N * 2 + 5], ans[N * 2 + 5];
int n;
void dfs(int u) {
  for (int &i = hd[u]; i; i = e[i].nxt)
    if (!ans[i >> 1]) ans[i >> 1] = (u < N) + 1, dfs(e[i].to);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i <= n; i++)
    scanf("%d%d", &u, &v), v += N, add(u, v), add(v, u), deg[u]++, deg[v]++;
  for (int i = 1; i <= N * 2; i++)
    if (deg[i] & 1) add(i, 0), add(0, i);
  for (int i = 1; i <= N; i++) dfs(i);
  for (int i = 1; i <= n; i++) putchar(ans[i] - 1 ? 'b' : 'r');
}
