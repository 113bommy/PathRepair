#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long dx[4] = {0, 0, -1, 1};
long long dy[4] = {1, -1, 0, 0};
int n, m, q;
char s[11];
long long bz[100010 << 1][52];
int pos[100010 << 1][52];
int head[100010 << 1], nex[100010 << 1], val[100010 << 1], op[100010 << 1], tot;
int T[100010 << 2];
void pushdown(int rt) {
  if (T[rt]) {
    T[rt << 1] = T[rt << 1 | 1] = T[rt];
    T[rt] = 0;
  }
}
void insert(int l, int r, int rt, int x, int y, int v) {
  if (x <= l && r <= y) {
    T[rt] = v;
    return;
  }
  int mid = l + r >> 1;
  pushdown(rt);
  if (mid >= x) insert(l, mid, rt << 1, x, y, v);
  if (mid < y) insert(mid + 1, r, rt << 1 | 1, x, y, v);
}
int query(int l, int r, int rt, int v) {
  if (l == r) return T[rt];
  int mid = l + r >> 1;
  pushdown(rt);
  if (mid >= v)
    return query(l, mid, rt << 1, v);
  else
    return query(mid + 1, r, rt << 1 | 1, v);
}
void add(long long x, long long y, int tp) {
  tot++;
  nex[tot] = head[x];
  head[x] = tot;
  val[tot] = y;
  op[tot] = tp;
}
struct vec {
  long long x1, x2, y1, y2;
  int op;
  void read() {
    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    if (y1 < y2) op = 0;
    if (y1 > y2) op = 1;
    if (x1 > x2) op = 2;
    if (x1 < x2) op = 3;
  }
} a[100010];
struct node {
  int op;
  long long len, x, y;
  void read() {
    scanf("%I64d%I64d%s%I64d", &x, &y, s, &len);
    if (s[0] == 'U') op = 0;
    if (s[0] == 'D') op = 1;
    if (s[0] == 'L') op = 2;
    if (s[0] == 'R') op = 3;
  }
} b[100010];
pair<long long, long long> cal(long long x, long long y, int p) {
  if (a[p].x1 == a[p].x2) {
    if (a[p].x1 == x) {
      if (min(a[p].y1, a[p].y2) <= y && y <= max(a[p].y1, a[p].y2))
        return make_pair(x, y);
      if (y < min(a[p].y1, a[p].y2))
        return make_pair(x, min(a[p].y1, a[p].y2));
      else
        return make_pair(x, max(a[p].y1, a[p].y2));
    } else
      return make_pair(a[p].x1, y);
  } else {
    if (a[p].y1 == y) {
      if (min(a[p].x1, a[p].x2) <= x && x <= max(a[p].x1, a[p].x2))
        return make_pair(x, y);
      if (x < min(a[p].x1, a[p].x2))
        return make_pair(min(a[p].x1, a[p].x2), y);
      else
        return make_pair(max(a[p].x1, a[p].x2), y);
    } else
      return make_pair(x, a[p].y1);
  }
}
int dis(long long x1, long long y1, long long x2, long long y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
pair<long long, long long> find(long long x, long long y, int tp,
                                long long step) {
  return make_pair(x + step * dx[tp], y + step * dy[tp]);
}
void print(pair<long long, long long> p) {
  long long x = p.first, y = p.second;
  x = max(x, 0ll);
  x = min(x, (long long)m);
  y = max(y, 0ll);
  y = min(y, (long long)m);
  printf("%I64d %I64d\n", x, y);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i].read();
  q = read();
  for (int i = 1; i <= q; i++) b[i].read();
  for (int i = 0; i <= 3; i++) {
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(T, 0, sizeof(T));
    for (int j = 1; j <= q; j++)
      if (b[j].op == i) {
        if (i < 2)
          add(b[j].y, j + n, 1);
        else
          add(b[j].x, j + n, 1);
      }
    for (int j = 1; j <= n; j++) {
      if (i == 0) add(max(a[j].y1, a[j].y2), j, 0);
      if (i == 1) add(min(a[j].y1, a[j].y2), j, 0);
      if (i == 2) add(min(a[j].x1, a[j].x2), j, 0);
      if (i == 3) add(max(a[j].x1, a[j].x2), j, 0);
    }
    for (int j = 1; j <= n; j++)
      if (a[j].op == i) {
        if (i < 2)
          add(a[j].y2, j, 1);
        else
          add(a[j].x2, j, 1);
      }
    int now = (i == 0 || i == 3) ? m : 0;
    while (now != -1 && now != m + 1) {
      for (int j = head[now]; j; j = nex[j]) {
        if (!op[j]) {
          if (i < 2)
            insert(0, m, 1, min(a[val[j]].x1, a[val[j]].x2),
                   max(a[val[j]].x1, a[val[j]].x2), val[j]);
          else
            insert(0, m, 1, min(a[val[j]].y1, a[val[j]].y2),
                   max(a[val[j]].y1, a[val[j]].y2), val[j]);
        } else {
          int tmp;
          if (val[j] <= n) {
            if (i < 2)
              tmp = query(0, m, 1, a[val[j]].x1);
            else
              tmp = query(0, m, 1, a[val[j]].y1);
          } else {
            if (i < 2)
              tmp = query(0, m, 1, b[val[j] - n].x);
            else
              tmp = query(0, m, 1, b[val[j] - n].y);
          }
          pos[val[j]][0] = tmp;
          if (tmp) {
            if (val[j] <= n)
              bz[val[j]][0] =
                  abs(a[tmp].x2 - a[val[j]].x2) + abs(a[tmp].y2 - a[val[j]].y2);
            else
              bz[val[j]][0] = abs(a[tmp].x2 - b[val[j] - n].x) +
                              abs(a[tmp].y2 - b[val[j] - n].y);
          } else
            bz[val[j]][0] = 1ll << 50;
        }
      }
      if (i == 0 || i == 3)
        now--;
      else
        now++;
    }
  }
  for (int i = 1; i <= 50; i++) bz[0][i] = 1ll << 50;
  for (int i = 1; i <= 50; i++)
    for (int j = 1; j <= n + q; j++) {
      pos[j][i] = pos[pos[j][i - 1]][i - 1];
      bz[j][i] = bz[j][i - 1] + bz[pos[j][i - 1]][i - 1];
      bz[j][i] = min(bz[j][i], 1ll << 50);
    }
  for (int i = 1; i <= q; i++) {
    int tmp = i + n;
    long long t = b[i].len;
    for (int j = 50; j <= 0; j++)
      if (bz[tmp][j] <= t) {
        t -= bz[tmp][j];
        tmp = pos[tmp][j];
      }
    if (tmp == i + n) {
      if (pos[tmp][0]) {
        pair<long long, long long> tq = cal(b[i].x, b[i].y, pos[tmp][0]);
        int tw = dis(tq.first, tq.second, b[i].x, b[i].y);
        if (tw >= t)
          print(find(b[i].x, b[i].y, b[i].op, t));
        else
          print(find(tq.first, tq.second, a[pos[tmp][0]].op, t - tw));
      } else
        print(find(b[i].x, b[i].y, b[i].op, t));
    } else {
      if (!pos[tmp][0])
        print(find(a[tmp].x2, a[tmp].y2, a[tmp].op, t));
      else {
        pair<long long, long long> tq = cal(a[tmp].x2, a[tmp].y2, pos[tmp][0]);
        int tw = dis(tq.first, tq.second, a[tmp].x2, a[tmp].y2);
        if (tw >= t)
          print(find(a[tmp].x2, a[tmp].y2, a[tmp].op, t));
        else
          print(find(tq.first, tq.second, a[pos[tmp][0]].op, t - tw));
      }
    }
  }
  return 0;
}
