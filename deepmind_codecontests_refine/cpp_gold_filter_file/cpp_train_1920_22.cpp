#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int h = 0, t = 1;
  while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == '-') t = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') h = h * 10 + ch - '0', ch = getchar();
  return h * t;
}
const int N = 1e5 + 100;
struct edge {
  int next, to;
} a[N << 1];
int head[N], cnt, n, m, dis[N], in[N], P[N], cc;
int dp[N], dep[N], b[N], ans;
queue<int> Q;
long long Ans;
struct Table {
  int ST[17][N], log[N];
  void build() {
    for (int p = 1; p <= 16; p++)
      for (int i = 1; i <= cc; i++)
        ST[p][i] = max(ST[p - 1][i], ST[p - 1][i + (1 << (p - 1))]);
    for (int i = 1; i <= 16; i++) log[1 << i] = i;
    for (int res = 0, i = 1; i <= cc; i++) log[i] ? res = log[i] : log[i] = res;
  }
  int q(int l, int r) {
    if (l > r) return -100000000;
    int d = log[r - l + 1];
    return max(ST[d][l], ST[d][r - (1 << d) + 1]);
  }
} A, B;
int bfs(int x) {
  memset(dis, -1, sizeof(dis));
  Q.push(x);
  dis[x] = 1;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int i = head[x]; i; i = a[i].next)
      if (dis[a[i].to] == -1) dis[a[i].to] = dis[x] + 1, Q.push(a[i].to);
  }
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[x]) x = i;
  return x;
}
int dfs(int x, int gl, int fr) {
  if (x == gl) {
    P[cc = 1] = x;
    in[x] = 1;
    return 1;
  }
  for (int i = head[x]; i; i = a[i].next) {
    if (a[i].to == fr) continue;
    int k = dfs(a[i].to, gl, x);
    if (k) {
      P[++cc] = x;
      in[x] = cc;
      return 1;
    }
  }
  return 0;
}
void dfs1(int x, int fr, int bl) {
  dep[x] = dep[fr] + 1;
  b[x] = bl;
  for (int i = head[x]; i; i = a[i].next) {
    if (a[i].to == fr || in[a[i].to]) continue;
    dfs1(a[i].to, x, bl);
    dp[x] = max(dp[x], dp[a[i].to] + 1);
  }
}
int Dis(int x, int y) {
  if (b[x] == b[y]) return abs(dep[x] - dep[y]);
  return dep[x] + dep[y] + abs(b[x] - b[y]);
}
void Max(int &x, int y) {
  if (y > x) x = y;
}
int main() {
  n = read();
  dep[0] = -1;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    a[++cnt] = (edge){head[x], y};
    head[x] = cnt;
    a[++cnt] = (edge){head[y], x};
    head[y] = cnt;
  }
  int l1 = bfs(1), l2 = bfs(l1);
  dfs(l2, l1, 0);
  for (int i = 1; i <= cc; i++) dfs1(P[i], 0, i);
  for (int i = 1; i <= cc; i++)
    A.ST[0][i] = dp[P[i]] + i, B.ST[0][i] = dp[P[i]] - i;
  A.build();
  B.build();
  int m = read(), x, y;
  for (int i = 1; i <= m; i++) {
    x = read();
    y = read();
    int d = Dis(x, y) / 2;
    ans = d;
    if (d < max(dep[x], dep[y])) {
      Max(ans, min(Dis(l1, x), Dis(l1, y)));
      Max(ans, min(Dis(l2, x), Dis(l2, y)));
    } else {
      if (b[x] > b[y]) swap(x, y);
      d -= dep[x];
      int mid = b[x] + d;
      Max(ans, max(Dis(l1, x), Dis(l2, y)));
      int d1 = dep[x] + A.q(b[x] + 1, mid) - b[x];
      int d2 = dep[y] + B.q(mid + 1, b[y] - 1) + b[y];
      if (d1 > 0) Max(ans, d1);
      if (d2 > 0) Max(ans, d2);
    }
    printf("%d\n", ans);
  }
}
