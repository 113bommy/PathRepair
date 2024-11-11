#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
const int M = 1e6 + 10;
struct bian {
  long long from, to, w, tag;
} eg[M << 1];
long long front[N], num;
void add(long long x, long long y, long long w) {
  eg[++num].to = y;
  eg[num].from = front[x];
  front[x] = num;
  eg[num].w = w;
  eg[num].tag = 1;
  swap(x, y);
  eg[++num].to = y;
  eg[num].from = front[x];
  front[x] = num;
}
long long s, t;
long long _front[N], dis[N];
bool bfs() {
  queue<int> q;
  q.push(s);
  memset(dis, 0, sizeof(dis));
  dis[s] = 1;
  while (!q.empty()) {
    long long o = q.front();
    q.pop();
    for (long long i = front[o]; i; i = eg[i].from) {
      long long to = eg[i].to;
      if (dis[to] == 0 && eg[i].w) {
        dis[to] = dis[o] + 1;
        q.push(to);
      }
    }
  }
  return dis[t] != 0;
}
long long dfs(int o, long long lim) {
  if (o == t) return lim;
  long long mins = 0;
  for (long long &i = _front[o]; i; i = eg[i].from) {
    long long to = eg[i].to;
    if (eg[i].w == 0 || dis[to] != dis[o] + 1) continue;
    long long now = dfs(to, min(lim - mins, eg[i].w));
    if (now) {
      eg[i].w -= now;
      eg[((i - 1) ^ 1) + 1].w += now;
      mins += now;
      if (mins == lim) break;
    }
  }
  return mins;
}
long long dinic() {
  long long re = 0;
  while (bfs()) {
    memcpy(_front, front, sizeof(front));
    re += dfs(s, 2e9);
  }
  return re;
}
int n, m;
int tot;
void build1(int o, int l, int r) {
  tot = max(tot, o);
  if (l == r) return;
  add(o, o << 1, 1e9);
  add(o, o << 1 | 1, 1e9);
  int mid = (l + r) >> 1;
  build1(o << 1, l, mid);
  build1(o << 1 | 1, mid + 1, r);
}
void build2(int o, int l, int r) {
  if (l == r) {
    add(o, tot + l, 1);
    return;
  }
  int mid = (l + r) >> 1;
  build2(o << 1, l, mid);
  build2(o << 1 | 1, mid + 1, r);
}
void adds(int o, int l, int r, int L, int R, int now) {
  if (L <= l && r <= R) {
    add(now, o, 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= L) adds(o << 1, l, mid, L, R, now);
  if (mid < R) adds(o << 1 | 1, mid + 1, r, L, R, now);
}
int dy[N], has[N];
int find(int o) {
  if (o > tot + m && o <= tot + m + n) return o - tot - m;
  for (int i = front[o]; i; i = eg[i].from) {
    int to = eg[i].to;
    if (eg[i].tag == 1 || eg[i].w == 0) continue;
    --eg[i].w;
    return find(to);
  }
  return 0;
}
int OMG[N][4];
int main() {
  scanf("%d%d", &n, &m);
  build1(1, 1, m);
  build2(1, 1, m);
  s = tot + n + m;
  t = s + 1;
  for (int i = 1; i <= m; ++i) add(i + tot, t, 1);
  for (int i = 1; i <= n; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 0) {
      add(s, tot + m + i, 1);
      int k;
      scanf("%d", &k);
      while (k--) {
        int now;
        scanf("%d", &now);
        add(tot + m + i, tot + now, 1);
      }
    }
    if (op == 1) {
      add(s, tot + m + i, 1);
      int l, r;
      scanf("%d%d", &l, &r);
      adds(1, 1, n, l, r, tot + m + i);
    }
    if (op == 2) {
      OMG[i][0] = 1;
      add(s, tot + m + i, 2);
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      OMG[i][1] = a;
      OMG[i][2] = b;
      OMG[i][3] = c;
      add(tot + m + i, tot + a, 1);
      add(tot + m + i, tot + b, 1);
      add(tot + m + i, tot + c, 1);
    }
  }
  printf("%d\n", dinic());
  for (int i = 1; i <= m; ++i) {
    dy[i] = find(i + tot);
    ++has[dy[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (OMG[i][0] == 1 && has[i] == 1) {
      if (dy[OMG[i][1]] != i)
        dy[OMG[i][1]] = i;
      else
        dy[OMG[i][2]] = i;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (dy[i]) printf("%d %d\n", dy[i], i);
  }
}
