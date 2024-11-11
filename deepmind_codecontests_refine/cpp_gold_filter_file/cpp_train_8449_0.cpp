#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 0x3f3f3f3f;
int n, m, cnt = -1, p[maxn], dep[maxn], cur[maxn], s, t, zx[maxn], zy[maxn],
          cntx, cnty;
struct kkk {
  int lx, ly, rx, ry;
} a[maxn];
struct node {
  int v, next, cap, flow;
} e[maxn * 10];
void add(int u, int v, int cap, int flow) {
  cnt++;
  e[cnt].v = v;
  e[cnt].next = p[u];
  e[cnt].cap = cap;
  e[cnt].flow = flow;
  p[u] = cnt;
}
bool bfs() {
  queue<int> q;
  memset(dep, -1, sizeof(dep));
  q.push(s);
  dep[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = p[u]; i != -1; i = e[i].next) {
      if (e[i].cap - e[i].flow > 0 && dep[e[i].v] == -1) {
        dep[e[i].v] = dep[u] + 1;
        q.push(e[i].v);
      }
    }
  }
  if (dep[t] == -1) return false;
  return true;
}
int dfs(int u, int maxflow) {
  if (u == t || maxflow == 0) return maxflow;
  int flow = 0;
  for (int &i = cur[u]; i != -1; i = e[i].next) {
    if (dep[e[i].v] == dep[u] + 1 && e[i].cap > e[i].flow) {
      int fl = dfs(e[i].v, min(maxflow, e[i].cap - e[i].flow));
      maxflow -= fl;
      flow += fl;
      e[i].flow += fl;
      e[i ^ 1].flow -= fl;
      if (maxflow == 0) break;
    }
  }
  return flow;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = s; i <= t; i++) {
      cur[i] = p[i];
    }
    ans += dfs(s, inf);
  }
  return ans;
}
int main() {
  memset(p, -1, sizeof(p));
  int n, m;
  cin >> n >> m;
  s = 0, t = 201;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &a[i].lx, &a[i].ly, &a[i].rx, &a[i].ry);
    a[i].lx--;
    a[i].ly--;
    zx[++cntx] = a[i].lx;
    zx[++cntx] = a[i].rx;
    zy[++cnty] = a[i].ly;
    zy[++cnty] = a[i].ry;
  }
  sort(zx + 1, zx + cntx + 1);
  sort(zy + 1, zy + cnty + 1);
  cntx = unique(zx + 1, zx + cntx + 1) - zx - 1;
  cnty = unique(zy + 1, zy + cnty + 1) - zy - 1;
  for (int i = 2; i <= cntx; i++) {
    for (int j = 2; j <= cnty; j++) {
      for (int k = 1; k <= m; k++) {
        if (a[k].lx <= zx[i - 1] && a[k].rx >= zx[i] && a[k].ly <= zy[j - 1] &&
            a[k].ry >= zy[j]) {
          add(i, j + 100, inf, 0);
          add(j + 100, i, 0, 0);
          break;
        }
      }
    }
  }
  for (int i = 2; i <= cntx; i++)
    add(s, i, zx[i] - zx[i - 1], 0), add(i, s, 0, 0);
  for (int i = 2; i <= cnty; i++)
    add(i + 100, t, zy[i] - zy[i - 1], 0), add(t, i + 100, 0, 0);
  cout << dinic();
  return 0;
}
