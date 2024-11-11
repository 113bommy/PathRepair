#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct edge {
  int t, nxt;
} e[maxn];
int n, m, d, cnt, top, qcnt, vcnt, tcnt;
bool ins[maxn];
int sta[maxn], head[maxn], low[maxn], dfn[maxn];
int bel[maxn], vis[maxn][51], dp[maxn][51];
int vis2[maxn];
char s[maxn][51];
pair<int, int> q[50 * maxn];
vector<int> cir[maxn];
void add_edge(int i, int x, int y) {
  e[i].t = y;
  e[i].nxt = head[x];
  head[x] = i;
}
void tarjan(int x) {
  low[x] = dfn[x] = ++cnt;
  ins[x] = 1;
  sta[++top] = x;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].t;
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else {
      if (ins[y]) low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    qcnt++;
    int t;
    do {
      t = sta[top--];
      ins[t] = 0;
      bel[t] = qcnt;
      cir[qcnt].push_back(t);
    } while (t != x);
  }
}
void runthecir(int xx, int yy) {
  int l = 1, r = 0;
  q[++r] = make_pair(xx, yy);
  vis[xx][yy] = ++vcnt;
  while (l <= r) {
    int x = q[l].first, y = q[l].second;
    l++;
    for (int i = head[x]; i; i = e[i].nxt) {
      int u = e[i].t;
      if (bel[u] == bel[x] && !vis[u][(y + 1) % d]) {
        vis[u][(y + 1) % d] = vcnt;
        q[++r] = make_pair(u, (y + 1) % d);
      }
    }
  }
  int sum = 0;
  tcnt++;
  for (int i = 1; i <= r; i++) {
    if (s[q[i].first][q[i].second] == '1' && vis2[q[i].first] != tcnt) {
      vis2[q[i].first] = tcnt;
      sum++;
    }
  }
  for (int i = 1; i <= r; i++) dp[q[i].first][q[i].second] = sum;
}
int dfs(int x, int y) {
  if (vis[x][y]) return dp[x][y];
  runthecir(x, y);
  int sum = 0;
  for (int i = 0; i <= (int)(cir[bel[x]].size()) - 1; i++) {
    int u = cir[bel[x]][i];
    for (int j = 0; j <= d - 1; j++) {
      if (vis[u][j] == vis[x][y]) {
        for (int k = head[u]; k; k = e[k].nxt) {
          if (bel[e[k].t] != bel[x]) sum = max(sum, dfs(e[k].t, (j + 1) % d));
        }
      }
    }
  }
  for (int i = 0; i <= (int)(cir[bel[x]].size()) - 1; i++) {
    int u = cir[bel[x]][i];
    for (int j = 0; j <= d - 1; j++) {
      if (vis[u][j] == vis[x][y]) dp[u][j] += sum;
    }
  }
  return dp[x][y];
}
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(i, x, y);
  }
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  int ans = dfs(1, 0);
  printf("%d", ans);
  return 0;
}
