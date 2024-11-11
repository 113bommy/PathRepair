#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int maxm = 10000;
const int Inf = 1e9 + 7;
struct Edge {
  int u, v, cap, flow, cost;
  int next;
} e[maxm];
int n, m, t;
int fi[maxn], ecnt;
int flow, cost;
int inq[maxn], fa[maxn], b[maxn];
int d[maxn], a[maxn], num[maxn];
char st[110];
int q[2 * maxn], head, tail;
void add_edge(int u, int v, int cap, int cost) {
  e[ecnt] = (Edge){u, v, cap, 0, cost, fi[u]};
  fi[u] = ecnt++;
}
bool spfa(int s, int t) {
  for (int i = 1; i <= 199; i++) d[i] = Inf;
  memset(inq, 0, sizeof(inq));
  d[s] = 0, inq[s] = 1, fa[s] = 0, a[s] = Inf;
  head = 0, tail = 0;
  q[tail++] = s;
  while (head < tail) {
    int x = q[head++];
    inq[x] = 0;
    for (int i = fi[x]; i != -1; i = e[i].next) {
      int v = e[i].v;
      if (e[i].cap > e[i].flow && d[v] > e[i].cost + d[x]) {
        if (i == 2) v = v;
        d[v] = d[x] + e[i].cost;
        fa[v] = i;
        a[v] = min(a[x], e[i].cap - e[i].flow);
        if (!inq[v]) q[tail++] = v, inq[v] = 1;
      }
    }
  }
  if (d[t] == Inf) return false;
  flow += a[t], cost -= d[t] * a[t];
  int u = t;
  while (u != s) {
    e[fa[u]].flow += a[t];
    e[fa[u] ^ 1].flow -= a[t];
    u = e[fa[u]].u;
  }
  return true;
}
int main() {
  t = 199;
  memset(fi, -1, sizeof(fi));
  scanf("%d", &n);
  scanf("%s", st);
  for (int i = 0; i < n; i++) num[st[i] - 'a']++;
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    int v = n - 1 - i, x, y;
    if (b[i] >= b[v]) {
      x = i, y = v;
    } else {
      x = v, y = i;
    }
    ans += b[x];
    num[st[x] - 'a']--;
    for (int j = 1; j <= 26; j++) {
      if (j == st[x] - 'a' + 1) continue;
      int w = 0;
      if (st[y] - 'a' + 1 == j) w = b[y];
      add_edge(j, 27 + i, 1, -w);
      add_edge(27 + i, j, 0, w);
    }
    add_edge(27 + i, t, 1, 0);
    add_edge(t, 27 + i, 0, 0);
  }
  for (int i = 0; i < 5; i++) {
    add_edge(0, i + 1, num[i], 0);
    add_edge(i + 1, 0, 0, 0);
  }
  while (spfa(0, t))
    ;
  printf("%d", cost + ans);
}
