#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct point {
  int to;
  int nxt;
} edge[maxn];
int n, m, k, tot, sta, is_draw;
int head[maxn], vis[maxn][2], out[maxn];
vector<int> st;
inline void add(int u, int v) {
  tot++;
  edge[tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
inline void dfs(int x, int col) {
  if (vis[x][col]) return;
  st.push_back(x);
  vis[x][col] = 1;
  if (!out[x]) {
    if (col) {
      printf("Win\n");
      int mm = st.size();
      for (int i = 0; i < mm; i++) printf("%d ", st[i]);
      exit(0);
    }
  }
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (vis[v][!col]) is_draw = 1;
    dfs(v, !col);
  }
  st.pop_back();
  vis[x][col] = 2;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int u;
      cin >> u;
      add(i, u);
      out[i]++;
    }
  }
  cin >> sta;
  dfs(sta, 0);
  if (is_draw)
    printf("Draw");
  else
    printf("Lose");
  return 0;
}
