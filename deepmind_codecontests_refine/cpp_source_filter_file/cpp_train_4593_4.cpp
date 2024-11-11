#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
struct cir {
  long long x, y, r;
};
point p[210], q[210], cur[210 * 2];
cir C[210];
long long MN, MX;
int n, m, cnt = 2, s = 1, t = 2, edge, head[410], nxt[1000000], a[1000000],
          r[1000000], dl[410], level[410], cur_head[410], id[210][2];
long long dis(point a) { return a.x * a.x + a.y * a.y; }
long long dot(point a, point b) { return a.x * b.x + a.y * b.y; }
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
point operator+(point a, point b) { return (point){a.x + b.x, a.y + b.y}; }
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
void create(int u, int v, int rest) {
  edge++;
  a[edge] = v;
  nxt[edge] = head[u];
  head[u] = edge;
  r[edge] = rest;
}
bool cmp(point a, point b) {
  if (a.x > 0 && b.x < 0) return true;
  if (a.x < 0 && b.x > 0) return false;
  return cross(a, b) >= 0;
}
void get_cur() {
  int c1 = 1, c2 = 1, now = 1;
  q[n + 1] = q[1];
  p[n + 1] = p[1];
  cur[1] = q[1];
  while (c1 != n + 1 || c2 != n + 1) {
    if (c1 == n + 1) {
      cur[now + 1] = cur[now] + (q[c2 + 1] - q[c2]);
      c2++;
    } else if (c2 == n + 1) {
      cur[now + 1] = cur[now] + (p[c1 + 1] - p[c1]);
      c1++;
    } else if (cmp(p[c1 + 1] - p[c1], q[c2 + 1] - q[c2])) {
      cur[now + 1] = cur[now] + (p[c1 + 1] - p[c1]);
      c1++;
    } else {
      cur[now + 1] = cur[now] + (q[c2 + 1] - q[c2]);
      c2++;
    }
    now++;
  }
  m = now;
  MN = MX = cur[1].x;
  for (int i = 2; i <= m; i++) MX = max(MX, cur[i].x);
}
long double get_dis(point x) {
  long double res = 1e18;
  int flag = 1;
  for (int i = 1; i <= m - 1; i++) {
    res = min(res, (long double)sqrt(dis(x - cur[i])));
    if (cross(cur[i + 1] - cur[i], x - cur[i]) < 0) flag = 0;
    long long t1 = dot(cur[i + 1] - cur[i], x - cur[i]),
              t2 = dis(cur[i + 1] - cur[i]);
    if (t1 >= 0 && t1 <= t2) {
      long double now = sqrt(dis(x - cur[i]) - ((long double)t1 / t2 * t1));
      res = min(res, now);
    }
  }
  if (flag) return -1;
  return res;
}
bool check(int x, int y) {
  long double tmp = get_dis((point){C[y].x - C[x].x, C[y].y - C[x].y}),
              need = C[x].r + C[y].r;
  return tmp < need;
}
void build() {
  int lef = 1, righ = 1;
  dl[1] = s;
  for (int i = 1; i <= cnt; i++) {
    level[i] = 0;
    cur_head[i] = head[i];
  }
  level[s] = 1;
  while (lef <= righ) {
    int u = dl[lef];
    for (int i = head[u]; i; i = nxt[i]) {
      int v = a[i];
      if (r[i] && level[v] == 0) {
        level[v] = level[u] + 1;
        dl[++righ] = v;
      }
    }
    lef++;
  }
}
int dinic(int u, int flow) {
  if (u == t) return flow;
  int ans = 0;
  for (int i = cur_head[u]; i; i = nxt[i]) {
    int v = a[i];
    cur_head[u] = i;
    if (r[i] && level[v] == level[u] + 1) {
      int low = dinic(v, min(flow, r[i]));
      ans += low;
      flow -= low;
      r[i] -= low;
      if (i % 2)
        r[i + 1] += low;
      else
        r[i - 1] += low;
      if (flow == 0) return ans;
    }
  }
  if (ans == 0) level[u] = -1;
  return ans;
}
int main() {
  int w, ch = 1;
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &p[i].x, &p[i].y);
    p[i + n] = p[i];
  }
  for (int i = 2; i <= n; i++)
    if (p[i].x < p[ch].x || p[i].x == p[ch].x && p[i].y < p[ch].y) ch = i;
  for (int i = 1; i <= n; i++) {
    p[i] = p[ch + i - 1];
    q[i].x = -p[i].x;
    q[i].y = -p[i].y;
    q[i + n] = q[i];
  }
  point tmp = q[1];
  ch = 1;
  for (int i = 2; i <= n; i++)
    if (q[i].x < q[ch].x || q[i].x == q[ch].x && q[i].y < q[ch].y) ch = i;
  for (int i = 1; i <= n; i++) {
    q[i] = q[ch + i - 1];
    q[i].x -= tmp.x;
    q[i].y -= tmp.y;
  }
  get_cur();
  int tot;
  scanf("%d", &tot);
  for (int i = 1; i <= tot; i++) {
    scanf("%I64d%I64d%I64d", &C[i].x, &C[i].y, &C[i].r);
    id[i][0] = ++cnt;
    id[i][1] = ++cnt;
    create(cnt - 1, cnt, 1);
    create(cnt, cnt - 1, 0);
    if (MN < -C[i].x + C[i].r) {
      create(s, id[i][0], 2147483647);
      create(id[i][0], s, 0);
    }
    if (MX > w - C[i].x - C[i].r) {
      create(id[i][1], t, 2147483647);
      create(t, id[i][1], 0);
    }
  }
  for (int i = 1; i <= tot; i++)
    for (int j = i + 1; j <= tot; j++)
      if (check(i, j)) {
        create(id[i][1], id[j][0], 2147483647);
        create(id[j][0], id[i][1], 0);
        create(id[j][1], id[i][0], 2147483647);
        create(id[i][0], id[j][1], 0);
      }
  int res = 0;
  build();
  while (level[t]) {
    res += dinic(s, 2147483647);
    build();
  }
  printf("%d\n", res);
  return 0;
}
