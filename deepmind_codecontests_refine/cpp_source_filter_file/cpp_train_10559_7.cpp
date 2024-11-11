#include <bits/stdc++.h>
using namespace std;
const int MN = 2005;
int n, to[MN * MN], nxt[MN * MN], h[MN], cnt;
inline void ins(int s, int t) {
  to[++cnt] = t;
  nxt[cnt] = h[s];
  h[s] = cnt;
}
int dfn[MN], low[MN], stk[MN], top, scnt, idx;
bool vis[MN];
void dfs(int st) {
  dfn[st] = low[st] = ++idx;
  vis[stk[++top] = st] = true;
  for (register int i = h[st]; i; i = nxt[i]) {
    if (!dfn[to[i]])
      dfs(to[i]), low[st] = min(low[st], low[to[i]]);
    else if (vis[to[i]])
      low[st] = min(low[st], dfn[to[i]]);
  }
  if (low[st] == dfn[st]) {
    scnt++;
    while (stk[top + 1] != st) vis[stk[top]] = false, top--;
  }
}
int main() {
  scanf("%d", &n);
  for (register int i = 1, x; i <= n; i++)
    for (register int j = 1; j <= n; j++) {
      scanf("%d", &x);
      if (x && i != j) ins(i, j);
    }
  for (register int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  puts(scnt > 1 ? "No" : "Yes");
  return 0;
}
