#include <bits/stdc++.h>
using namespace std;
int fa[101000][20], h[101000], lev[101000], ans[101000];
int dp[101000];
struct EDGE {
  int to, nxt;
} box[2 * 101000];
int top, K;
void add(int u, int v) {
  box[top].to = v;
  box[top].nxt = h[u];
  h[u] = top++;
}
void DFS(int u, int pre, int t) {
  lev[u] = lev[pre] + 1;
  fa[u][0] = pre;
  if (!t)
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int p = h[u]; p != -1; p = box[p].nxt) {
    int v = box[p].to;
    if (pre == v) continue;
    DFS(v, u, t);
    if (t) {
      dp[u] += dp[v];
      ans[p / 2] = dp[v];
    }
  }
}
int lca(int u, int v) {
  if (lev[u] < lev[v]) swap(u, v);
  int c = lev[u] - lev[v];
  for (int i = 19; i >= 0; i--) {
    if (c & (1 << i)) {
      u = fa[u][i];
      c -= (1 << i);
    }
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}
int main() {
  int n, k;
  int a, b;
  scanf("%d", &n);
  memset(h, -1, sizeof(h));
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    add(a, b);
    add(b, a);
  }
  DFS(1, 1, 0);
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &a, &b);
    int c = lca(a, b);
    dp[a]++;
    dp[b]++;
    dp[c] -= 2;
  }
  DFS(1, 1, 1);
  for (int i = 0; i < n - 1; i++) {
    printf("%d%c", ans[i], i == n - 2 ? '\n' : ' ');
  }
}
