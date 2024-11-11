#include <bits/stdc++.h>
using namespace std;
int fa[333], a[333], b[333];
long long has[333], need[333];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
vector<int> e[333];
struct node {
  int x, y, d;
  node() {}
  node(int xx, int yy, int dd) { x = xx, y = yy, d = dd; }
} q[1000050], cost[1000050];
int tail = 0;
int n, v, m;
struct info {
  int x, y;
} over[333], less1[333];
bool cmp(info a, info b) { return a.y > b.y; }
int cnt = 0;
int pre[333];
bool bo[333];
void dfs(int cur, int fa, int ed) {
  bo[cur] = true;
  pre[cur] = fa;
  if (ed == cur) {
    return;
  }
  for (int i = 0; i < e[cur].size(); ++i) {
    int u = e[cur][i];
    if (!bo[u]) dfs(u, cur, ed);
  }
}
int path[333];
int pnum;
void getpath(int now) {
  if (pre[now] != -1) getpath(pre[now]);
  path[pnum++] = now;
}
void run(int now, int flow) {
  if (flow == 0) return;
  if (now == pnum - 1) return;
  int x = path[now], y = path[now + 1];
  if (v - a[y] >= flow) {
    q[tail++] = node(x, y, flow);
    run(now + 1, flow);
  } else {
    int tmp = v - a[y];
    if (tmp != 0) q[tail++] = node(x, y, tmp);
    run(now + 1, flow);
    if (flow - tmp != 0) q[tail++] = node(x, y, flow - tmp);
  }
}
void gao(int i) {
  dfs(cost[i].x, -1, cost[i].y);
  pnum = 0;
  getpath(cost[i].y);
  run(0, cost[i].d);
  a[cost[i].x] -= cost[i].d;
  a[cost[i].y] += cost[i].d;
}
void solve(int cur) {
  int p1, p2;
  p1 = p2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (getfa(i) == cur) {
      if (a[i] > b[i]) {
        over[p1].y = a[i] - b[i];
        over[p1++].x = i;
      } else if (b[i] > a[i]) {
        less1[p2].y = b[i] - a[i];
        less1[p2++].x = i;
      }
    }
  }
  sort(over, over + p1, cmp);
  sort(less1, less1 + p2, cmp);
  int l, r;
  l = r = 0;
  cnt = 0;
  for (int i = 0; i < p2; ++i) {
    while (less1[i].y > 0) {
      if (over[r].y > less1[i].y) {
        over[r].y -= less1[i].y;
        cost[cnt++] = node(over[r].x, less1[i].x, less1[i].y);
        less1[i].y = 0;
      } else {
        less1[i].y -= over[r].y;
        cost[cnt++] = node(over[r].x, less1[i].x, over[r].y);
        over[r].y = 0;
        r++;
      }
    }
  }
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j <= n; ++j) bo[j] = false;
    gao(i);
  }
}
int aa[333], bb[333];
void check() {
  for (int i = 0; i < tail; ++i) {
    aa[q[i].x] -= q[i].d;
    aa[q[i].y] += q[i].d;
    if (aa[q[i].y] > v)
      while (1)
        ;
    if (aa[q[i].y] < 0)
      while (1)
        ;
  }
}
int main() {
  scanf("%d%d%d", &n, &v, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    aa[i] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    bb[i] = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    has[i] = a[i];
    need[i] = b[i];
    fa[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
    int f1 = getfa(x);
    int f2 = getfa(y);
    fa[f1] = f2;
    has[f2] += has[f1];
    need[f2] += need[f1];
  }
  int flag = 1;
  for (int i = 1; i <= n && flag; ++i) {
    if (getfa(i) == i) {
      if (has[i] != need[i]) {
        flag = 0;
        break;
      }
      solve(i);
    }
  }
  if (flag == 0)
    puts("NO");
  else {
    if (tail > n * n * 2)
      while (1)
        ;
    check();
    printf("%d\n", tail);
    for (int i = 0; i < tail; ++i) printf("%d %d %d\n", q[i].x, q[i].y, q[i].d);
  }
}
