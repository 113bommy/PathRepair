#include <bits/stdc++.h>
using namespace std;
int n, m, k, T, head[1010], o = 0, deg[1010], id[1010];
int tpn[1010], l = 1, r = 0, cnt = 0;
int vis[1050000], st[4300][3];
char s[100];
struct edge {
  int to, link;
} e[100010];
void add_edge(int u, int v) {
  e[++o].to = v, e[o].link = head[u], head[u] = o, deg[v]++;
}
queue<int> q;
int find(int S) {
  while (!q.empty()) q.pop();
  q.push(S);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (!vis[now]) return now;
    for (int i = 0; i < k; i++) q.push(now ^ (1 << i));
  }
}
void opt(int op, int x, int y) {
  st[++cnt][0] = op, st[cnt][1] = x, st[cnt][2] = y;
}
int main() {
  scanf("%d%d%d", &n, &m, &T), k = min(n, 20);
  for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), add_edge(u, v);
  for (int i = 1; i <= n; i++)
    if (!deg[i]) tpn[++r] = i;
  while (l <= r) {
    int u = tpn[l];
    l++;
    for (int i = head[u]; i; i = e[i].link) {
      if (!--deg[e[i].to]) tpn[++r] = e[i].to;
    }
  }
  reverse(tpn + 1, tpn + n + 1);
  for (int i = 1; i <= k; i++) {
    id[tpn[i]] = i;
    for (int j = 1; j < i; j++) opt(1, tpn[i], tpn[j]);
  }
  for (int j = k + 1; j <= n; j++) {
    int u = tpn[j];
    opt(1, u, u);
    int S = 0, tmp;
    for (int i = head[u]; i; i = e[i].link)
      if (id[e[i].to]) S |= 1 << (id[e[i].to] - 1);
    tmp = find(S), vis[S] = u;
    for (int i = 0; i < k; i++)
      if (((tmp ^ S) >> i) & 1) opt((tmp >> i) & 1, u, tpn[i + 1]);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++)
    printf("%c %d %d\n", st[i][0] ? '+' : '-', st[i][1], st[i][2]);
  while (T--) {
    int S = 0, ans = 0;
    for (int i = 1; i <= k; i++) {
      printf("? 1 %d\n", tpn[i]);
      fflush(stdout);
      scanf("%s", s + 1);
      if (s[1] == 'L') {
        ans = tpn[i];
        break;
      } else if (s[1] == 'W')
        S |= 1 << (i - 1);
    }
    printf("! %d\n", ans ? ans : vis[S]);
    fflush(stdout);
    scanf("%s", s + 1);
  }
}
