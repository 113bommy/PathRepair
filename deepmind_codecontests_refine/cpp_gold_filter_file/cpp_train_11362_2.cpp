#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 5e5 + 5;
struct Edge {
  int v, nxt;
} e[N << 3];
int head[N], size;
void link(int u, int v) {
  e[++size].v = v;
  e[size].nxt = head[u];
  head[u] = size;
}
int n, tot, deg[N], du[N], flag;
char S[N];
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].nxt) ++deg[u];
  if (deg[u] > 3) {
    flag = 1;
    return;
  }
  du[u] += deg[fa] > 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    du[u] += deg[v] > 1;
    if (flag) return;
  }
  if (deg[u] == 3 && du[u] >= 2) {
    flag = 1;
    return;
  }
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= tot; ++i) head[i] = du[i] = deg[i] = 0;
    for (int i = 1; i <= size; ++i) e[i].v = e[i].nxt = 0;
    size = 0;
    for (int i = 1; i < n; ++i) {
      int x = read(), y = read();
      link(x, y);
      link(y, x);
    }
    tot = n;
    scanf("%s", S + 1);
    for (int i = 1; i <= n; ++i)
      if (S[i] == 'W') {
        link(i, tot + 1);
        link(tot + 1, i);
        link(tot + 1, tot + 2);
        link(tot + 2, tot + 1);
        link(tot + 1, tot + 3);
        link(tot + 3, tot + 1);
        tot += 3;
      }
    flag = 0;
    dfs(1, 0);
    int cnt = 0;
    for (int i = 1; i <= tot; ++i)
      if (deg[i] >= 3) ++cnt;
    if (cnt > 1 && (tot & 1)) flag = 1;
    if (flag)
      printf("White\n");
    else
      printf("Draw\n");
  }
  return 0;
}
