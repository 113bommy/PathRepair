#include <bits/stdc++.h>
using namespace std;
int head[3000000][2], last[3000000], to[3000000], R[3000000], cnt = 0,
                                                              f[3000000][2];
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
struct node {
  int x, y, l, r;
  friend bool operator<(node x, node y) { return x.l > y.l; }
} tmp;
priority_queue<node> q;
inline void ins(int u, int v, int r, int opt) {
  last[++cnt] = head[u][opt], head[u][opt] = cnt, to[cnt] = v, R[cnt] = r;
}
inline void update(int x, int l, int r, int opt) {
  int i;
  f[x][opt] = max(f[x][opt], r);
  for (i = head[x][opt]; i; i = last[i]) {
    tmp.l = l, tmp.r = R[i], tmp.x = x, tmp.y = to[i];
    q.push(tmp);
  }
  head[x][opt] = 0;
}
int main() {
  int n, m, i, u, v, l, r, x, y;
  n = read(), m = read();
  if (n == 1) puts("0"), exit(0);
  for (i = 1; i <= m; ++i) {
    u = read(), v = read(), l = read(), r = (read() - 1);
    tmp.x = u, tmp.y = v, tmp.l = l, tmp.r = r - ((r - l) % 2), q.push(tmp);
    tmp.x = v, tmp.y = u, tmp.l = l, tmp.r = r - ((r - l) % 2), q.push(tmp);
    tmp.x = u, tmp.y = v, tmp.l = l + 1, tmp.r = r - !((r - l) % 2),
    q.push(tmp);
    tmp.x = v, tmp.y = u, tmp.l = l + 1, tmp.r = r - !((r - l) % 2),
    q.push(tmp);
  }
  memset(f, 255, sizeof(f));
  f[1][0] = 0;
  while (!q.empty()) {
    tmp = q.top(), q.pop();
    x = tmp.x, y = tmp.y, l = tmp.l, r = tmp.r;
    if (l > r) continue;
    if (f[x][l & 1] >= l) {
      if (y == n) {
        printf("%d\n", l + 1);
        return 0;
      }
      update(y, l + 1, r + 1, (l & 1) ^ 1);
    } else
      ins(x, y, r, l & 1);
  }
  puts("-1");
  return 0;
}
