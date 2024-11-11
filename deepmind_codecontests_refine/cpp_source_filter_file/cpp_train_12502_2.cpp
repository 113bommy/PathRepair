#include <bits/stdc++.h>
using namespace std;
int n, m, totp, siz[200010];
int q[200010], top, totfinal = 0;
struct edge {
  int v, next;
  long long a, b;
};
bool vis[400010] = {0};
struct point {
  long long x, y;
} p[2][200010], pfinal[5000010];
point operator+(point a, point b) {
  point s;
  s.x = a.x + b.x, s.y = a.y + b.y;
  return s;
}
point operator-(point a, point b) {
  point s;
  s.x = a.x - b.x, s.y = a.y - b.y;
  return s;
}
struct tree {
  int first[200010], tot;
  edge e[400010];
  void insert(int u, int v, long long a, long long b) {
    e[++tot].v = v;
    e[tot].next = first[u];
    e[tot].a = a, e[tot].b = b;
    first[u] = tot;
  }
} t, tt;
void build(int v, int fa) {
  int now = 0, last;
  for (int i = t.first[v]; i; i = t.e[i].next)
    if (t.e[i].v != fa) {
      int y = t.e[i].v;
      if (!now)
        now = v;
      else {
        last = now, now = ++totp;
        tt.insert(last, now, 0, 0);
        tt.insert(now, last, 0, 0);
      }
      tt.insert(now, y, t.e[i].a, t.e[i].b);
      tt.insert(y, now, t.e[i].a, t.e[i].b);
      build(y, v);
    }
}
void dp(int v, int fa) {
  siz[v] = 1;
  for (int i = tt.first[v]; i; i = tt.e[i].next)
    if (!vis[i] && tt.e[i].v != fa) {
      int y = tt.e[i].v;
      q[++top] = i;
      dp(y, v);
      siz[v] += siz[tt.e[i].v];
    }
}
int findedge(int v) {
  top = 0;
  dp(v, 0);
  int mn = 1000000000, mni;
  if (!top) return 0;
  for (int i = 1; i <= top; i++)
    if (abs(siz[v] - (siz[tt.e[q[i]].v] << 1)) < mn) {
      mn = abs(siz[v] - (siz[tt.e[q[i]].v] << 1));
      mni = q[i];
    }
  return mni;
}
void dfs(int v, int fa, bool type, long long tota, long long totb) {
  p[type][++top].x = tota;
  p[type][top].y = totb;
  for (int i = tt.first[v]; i; i = tt.e[i].next)
    if (!vis[i] && tt.e[i].v != fa)
      dfs(tt.e[i].v, v, type, tota + tt.e[i].a, totb + tt.e[i].b);
}
bool cmp(point a, point b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
long long multi(point a, point b) { return a.x * b.y - a.y * b.x; }
void calc(int type, int &siz) {
  siz = 0;
  sort(p[type] + 1, p[type] + top + 1, cmp);
  for (int i = 1; i <= top; i++) {
    while (siz > 1) {
      point a = p[type][siz - 1], b = p[type][siz], c = p[type][i];
      if (multi(b - a, c - b) < 0) break;
      siz--;
    }
    p[type][++siz] = p[type][i];
  }
}
void merge(int siz0, int siz1, point add) {
  int i = 1, j = 1;
  while (true) {
    pfinal[++totfinal] = p[0][i] + p[1][j] + add;
    if (i == siz0 && j == siz1) break;
    if (i == siz0)
      j++;
    else if (j == siz1)
      i++;
    else if (multi(p[0][i + 1] - p[0][i], p[1][i + 1] - p[1][i]) < 0)
      i++;
    else
      j++;
  }
}
void solve(int v) {
  int now = findedge(v);
  if (!now) return;
  vis[now] = vis[now ^ 1] = 1;
  int x = tt.e[now].v, y = tt.e[now ^ 1].v;
  int siz0, siz1;
  top = 0, dfs(x, 0, 0, 0, 0), calc(0, siz0);
  top = 0, dfs(y, 0, 1, 0, 0), calc(1, siz1);
  point add;
  add.x = tt.e[now].a, add.y = tt.e[now].b;
  merge(siz0, siz1, add);
  solve(x), solve(y);
}
int main() {
  scanf("%d%d", &n, &m);
  memset(t.first, 0, sizeof(t.first));
  memset(tt.first, 0, sizeof(tt.first));
  t.tot = tt.tot = 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    long long a, b;
    scanf("%d%d%lld%lld", &u, &v, &a, &b);
    t.insert(u, v, a, b), t.insert(v, u, a, b);
  }
  totp = n;
  build(1, 0);
  pfinal[++totfinal].x = 0;
  pfinal[totfinal].y = 0;
  solve(1);
  int siz = 0;
  sort(pfinal + 1, pfinal + totfinal + 1, cmp);
  for (int i = 1; i <= totfinal; i++) {
    while (siz > 1) {
      point a = pfinal[siz - 1], b = pfinal[siz], c = pfinal[i];
      if (multi(b - a, c - b) < 0) break;
      siz--;
    }
    pfinal[++siz] = pfinal[i];
  }
  point T;
  T.x = 1;
  int now = 1;
  for (T.y = 0; T.y > -m; T.y--) {
    while (now != siz && multi(T, pfinal[now + 1] - pfinal[now]) >= 0) now++;
    printf("%I64d ", pfinal[now].x * (-T.y) + pfinal[now].y);
  }
  return 0;
}
