#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int a[40005], l[40005], b[40005], pos[40005], tot, d[70][40005], inq[1 << 15],
    f[1 << 15], cnt, head[40005];
struct edge {
  int to, nxt, val;
} e[40005 << 1];
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (c > '9' || c < '0') f = c == '-', c = getchar();
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return f ? -x : x;
}
inline void add(int u, int v, int k) {
  e[++cnt] = (edge){v, head[u], k}, head[u] = cnt;
  e[++cnt] = (edge){u, head[v], k}, head[v] = cnt;
}
inline int minn(int a, int b) { return a < b ? a : b; }
inline void bfs() {
  for (int i = 1; i <= tot; ++i) {
    d[i][pos[i]] = 0;
    queue<int> q;
    q.push(pos[i]);
    while (q.size()) {
      int x = q.front();
      q.pop();
      inq[x] = 0;
      for (int j = 1; j <= m; ++j) {
        int o = x + b[j], p = x - b[j];
        if (o <= n)
          if (d[i][o] > d[i][x] + 1) {
            d[i][o] = d[i][x] + 1;
            if (!inq[o]) inq[o] = 1, q.push(o);
          }
        if (p >= 1)
          if (d[i][p] > d[i][x] + 1) {
            d[i][p] = d[i][x] + 1;
            if (!inq[p]) inq[p] = 1, q.push(p);
          }
      }
    }
  }
}
inline void spfa() {
  queue<int> q;
  int N = (1 << tot) - 1;
  memset(f, 0x3f3f3f3f, sizeof(f)), f[N] = 0;
  q.push(N);
  while (q.size()) {
    int x = q.front();
    q.pop(), inq[x] = 0;
    for (int i = 1; i <= tot; ++i) {
      int u = 1 << (i - 1);
      for (int j = head[i]; j; j = e[j].nxt) {
        int v = 1 << (e[j].to - 1), z = x ^ u ^ v;
        if ((x & u) && (x & v)) {
          if (f[z] > f[x] + e[j].val) {
            f[z] = f[x] + e[j].val;
            if (!inq[z]) inq[z] = 1, q.push(z);
          }
        }
      }
    }
  }
}
int main() {
  n = read(), ++n, k = read(), m = read(), memset(d, 0x3f3f3f3f, sizeof(d));
  int x;
  for (int i = 1; i <= k; ++i) x = read(), a[x] = 1;
  for (int i = 1; i <= m; ++i) b[i] = read();
  for (int i = 1; i <= n; ++i) {
    l[i] = a[i] ^ a[i - 1];
    if (l[i]) pos[++tot] = i;
  }
  bfs();
  for (int i = 1; i <= tot; ++i)
    for (int j = i + 1; j <= tot; ++j) {
      int m_in = 0x3f3f3f3f;
      for (int u = 1; u <= n; ++u)
        if (d[i][u] != 0x3f3f3f3f && d[j][u] != 0x3f3f3f3f)
          m_in = minn(d[i][u] + d[j][u], m_in);
      if (m_in != 0x3f3f3f3f) add(i, j, m_in);
    }
  spfa();
  printf("%d", f[0] != 0x3f3f3f3f ? f[0] : -1);
  return 0;
}
