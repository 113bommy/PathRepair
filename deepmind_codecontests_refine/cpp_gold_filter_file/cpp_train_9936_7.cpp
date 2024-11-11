#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-6;
inline int lowbit(int x) { return x & (-x); }
inline int read() {
  int f = 1, x = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * x;
}
template <typename T>
inline T max(T x, T y, T z) {
  return max(max(x, y), z);
}
template <typename T>
inline T min(T x, T y, T z) {
  return min(min(x, y), z);
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
inline void checkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void checkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C yql) {
  A ans = 1;
  for (; p; p >>= 1, x = 1LL * x * x % yql)
    if (p & 1) ans = 1LL * x * ans % yql;
  return ans;
}
struct FastIO {
  static const int S = 1310720;
  int wpos;
  char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len) pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos++];
  }
  inline int read() {
    int c = xchar(), x = 0;
    while (c <= 32 && ~c) c = xchar();
    if (c == -1) return -1;
    for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
} io;
const int N = 100010;
int f[N], size[N], n, tot, head[N], vis[N], rt, cnt, sum;
struct Edge {
  int u, v, next;
} G[N << 1];
long long k, res, yql, val[N], in0[N], in1[N], out1[N], out0[N], pw1[N], pw2[N];
struct Node {
  long long w;
  long long x;
  bool operator<(const Node &q) const { return x < q.x; }
} up[N], dw[N];
inline void addedge(int u, int v) {
  G[++tot].u = u;
  G[tot].v = v;
  G[tot].next = head[u];
  head[u] = tot;
  G[++tot].u = v;
  G[tot].v = u;
  G[tot].next = head[v];
  head[v] = tot;
}
inline void getrt(int u, int fa) {
  size[u] = 1;
  f[u] = 0;
  for (int i = head[u]; i; i = G[i].next) {
    int v = G[i].v;
    if (v == fa || vis[v]) continue;
    getrt(v, u);
    size[u] += size[v];
    checkmax(f[u], size[v]);
  }
  checkmax(f[u], sum - size[u]);
  if (f[u] < f[rt]) rt = u;
}
inline Node make_Node(long long x, long long w) {
  Node cur;
  cur.w = w;
  cur.x = x;
  return cur;
}
inline void getdep(int x, int fa, int dep, long long su, long long sd) {
  su = (1LL * su * k % yql + val[x]) % yql;
  long long cur;
  if (dep == 0)
    cur = 0;
  else
    cur = pw1[dep - 1];
  sd = (sd + 1LL * val[x] * cur % yql) % yql;
  up[++cnt] = make_Node((res - su + yql) * pw2[dep + 1] % yql, x);
  dw[cnt] = make_Node(sd, x);
  for (int i = head[x]; i; i = G[i].next) {
    int v = G[i].v;
    if (v == fa || vis[v]) continue;
    getdep(v, x, dep + 1, su, sd);
  }
}
inline void calc(int x, int flag, int dep, long long su, long long sd) {
  cnt = 0;
  getdep(x, 0, dep, su, sd);
  sort(up + 1, up + cnt + 1);
  sort(dw + 1, dw + cnt + 1);
  int all = 0, i = 1, j = 1;
  for (int i = 1; i <= cnt; i++) {
    for (; j <= cnt && dw[j].x <= up[i].x; j++)
      if (j == 1 || dw[j].x != dw[j - 1].x)
        all = 1;
      else
        all++;
    if (j != 1 && dw[j - 1].x == up[i].x) out1[up[i].w] += all * flag;
  }
  all = 0;
  j = 1;
  for (int i = 1; i <= cnt; i++) {
    for (; j <= cnt && up[j].x <= dw[i].x; j++)
      if (j == 1 || up[j].x != up[j - 1].x)
        all = 1;
      else
        all++;
    if (j != 1 && up[j - 1].x == dw[i].x) in1[dw[i].w] += all * flag;
  }
}
inline void work(int x) {
  vis[x] = 1;
  calc(x, 1, 0, 0, 0);
  for (int i = head[x]; i; i = G[i].next) {
    int v = G[i].v;
    if (vis[v]) continue;
    calc(v, -1, 1, val[x], 0);
    sum = size[v];
    rt = 0;
    getrt(v, x);
    work(rt);
  }
}
int main() {
  read(n);
  read(yql);
  read(k);
  read(res);
  pw1[0] = 1;
  pw2[0] = 1;
  long long inv = fpow(k, yql - 2, yql);
  for (int i = 1; i <= n; i++) {
    pw1[i] = 1LL * pw1[i - 1] * k % yql;
    pw2[i] = 1LL * pw2[i - 1] * inv % yql;
  }
  for (int i = 1; i <= n; i++) read(val[i]);
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    addedge(u, v);
  }
  sum = f[0] = n;
  rt = 0;
  getrt(1, 0);
  work(rt);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += ((long long)2 * (n - in1[i]) * in1[i] +
            (long long)2 * (n - out1[i]) * out1[i] + (n - in1[i]) * out1[i] +
            (n - out1[i]) * in1[i]);
  cout << 1LL * n * n * n - ans / 2;
}
