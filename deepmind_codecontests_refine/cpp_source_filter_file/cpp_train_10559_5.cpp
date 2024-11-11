#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 20010;
int head[maxn], tol, dfn[maxn], low[maxn], indexx, top, Stack[maxn];
int instack[maxn], scc;
struct node {
  int next, to;
} edge[5020000];
void add(int u, int v) {
  edge[tol].to = v;
  edge[tol].next = head[u];
  head[u] = tol++;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++indexx;
  instack[u] = 1;
  Stack[top++] = u;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instack[v] && low[u] > dfn[v])
      low[u] = dfn[v];
  }
  if (low[u] == dfn[u]) {
    scc++;
    int v;
    do {
      v = Stack[--top];
      instack[v] = 1;
    } while (u != v);
  }
}
int main() {
  int n, i, j, k, m;
  while (cin >> n) {
    memset(head, -1, sizeof(head));
    tol = 0;
    memset(dfn, 0, sizeof(dfn));
    indexx = top = 0;
    memset(instack, 0, sizeof(instack));
    scc = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        scanf("%d", &k);
        if (k && i != j) add(i, j);
      }
    for (i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i);
    if (scc == 1)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
