#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
const int MAXM = 2e6 + 5;
const int inf = 1e9;
void read(int &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  x *= f;
}
int n, q;
int head[MAXN << 4], nxt[MAXM], to[MAXM], edge[MAXM], cnt = -1;
int rt1, rt2, tot, ch[MAXN << 4][2], val[MAXN << 4];
void add(int u, int v, int w) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
  edge[cnt] = w;
  nxt[++cnt] = head[v];
  head[v] = cnt;
  to[cnt] = u;
  edge[cnt] = 0;
}
int d[MAXN], s, t;
bool bfs() {
  memset(d, 0, sizeof d);
  queue<int> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = nxt[i]) {
      if (edge[i] && !d[to[i]]) {
        d[to[i]] = d[x] + 1;
        if (to[i] == t) return true;
        q.push(to[i]);
      }
    }
  }
  return false;
}
int Dinic(int x, int flow) {
  if (x == t) return flow;
  int rest = flow;
  for (int i = head[x]; i != -1 && rest; i = nxt[i]) {
    if (edge[i] && d[to[i]] == d[x] + 1) {
      int k = Dinic(to[i], min(rest, edge[i]));
      if (!k) d[to[i]] = 0;
      edge[i] -= k;
      edge[i ^ 1] += k;
      rest -= k;
    }
  }
  return flow - rest;
}
int ans;
void work() {
  while (bfs()) ans += Dinic(s, inf);
  printf("%d", ans);
}
void build(int l, int r, int &now, int ty) {
  if (!now) now = ++tot;
  val[now] = (r - l + 1);
  if (l == r) {
    if (!ty)
      add(s, now, 1);
    else
      add(now, t, 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, ch[now][0], ty);
  if (!ty)
    add(ch[now][0], now, inf);
  else if (ty)
    add(now, ch[now][0], inf);
  build(mid + 1, r, ch[now][1], ty);
  if (!ty)
    add(ch[now][1], now, inf);
  else if (ty)
    add(now, ch[now][1], inf);
}
vector<int> nod;
void find2(int l, int r, int now, int x, int y) {
  if (l >= x && r <= y) {
    nod.push_back(now);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) find2(l, mid, ch[now][0], x, y);
  if (y > mid) find2(mid + 1, r, ch[now][1], x, y);
}
void find1(int l, int r, int now, int x, int y) {
  if (l >= x && r <= y) {
    for (unsigned i = 0; i < nod.size(); ++i) {
      add(now, nod[i], inf);
    }
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) find1(l, mid, ch[now][0], x, y);
  if (y > mid) find1(mid + 1, r, ch[now][1], x, y);
}
void ADD_edges(int x1, int y1, int x2, int y2) {
  nod.clear();
  find2(1, n, rt2, y1, y2);
  find1(1, n, rt1, x1, x2);
}
struct matr {
  int x1, x2, y1, ty;
  matr() {}
  matr(int U, int D, int L, int T) {
    x1 = U;
    x2 = D;
    y1 = L;
    ty = T;
  }
} E[MAXN];
int num, a[MAXN];
void build_gragh() {
  fill(a, a + 1 + n, 1);
  for (int i = 1; i <= num; ++i) {
    if (E[i].ty == 1) {
      for (int j = E[i].x1; j <= E[i].x2; ++j) a[j] = E[i].y1;
    } else {
      int las = a[E[i].x1], lasp = E[i].x1;
      for (int j = E[i].x1; j <= E[i].x2; ++j) {
        if (las != a[j]) {
          if (las != E[i].y1) ADD_edges(lasp, las, j - 1, E[i].y1 - 1);
          las = a[j], lasp = j;
        }
      }
      if (E[i].y1 != las) ADD_edges(lasp, las, E[i].x2, E[i].y1 - 1);
    }
  }
}
bool cmpmatr(matr x, matr y) {
  if (x.y1 == y.y1) return x.ty > y.ty;
  return x.y1 < y.y1;
}
int main() {
  memset(head, -1, sizeof head);
  read(n);
  read(q);
  for (int i = 1; i <= q; ++i) {
    int x1, y1, x2, y2;
    read(x1);
    read(y1);
    read(x2);
    read(y2);
    E[++num] = matr(x1, x2, y1, 0);
    E[++num] = matr(x1, x2, y2 + 1, 1);
  }
  E[++num] = matr(1, n, n + 1, 0);
  sort(E + 1, E + 1 + num, cmpmatr);
  s = n * 5 + 1, t = n * 5 + 2;
  build(1, n, rt1, 0);
  build(1, n, rt2, 1);
  build_gragh();
  work();
  return 0;
}
