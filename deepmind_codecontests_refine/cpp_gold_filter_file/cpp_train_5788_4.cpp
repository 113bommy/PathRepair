#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
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
long long n, k, ans;
long long head[200020], pos;
struct edge {
  long long to, next, c;
} e[200020 << 1];
void add(long long a, long long b, long long c) {
  pos++;
  e[pos].to = b, e[pos].c = c, e[pos].next = head[a], head[a] = pos;
}
void insert(long long a, long long b, long long c) {
  add(a, b, c);
  add(b, a, c);
}
long long size[200020], f[200020], h[200020], g[200020][5];
void dp(long long u, long long fa) {
  f[u] = 0;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    long long t = e[i].c % k, s = e[i].c / k;
    if (v == fa) continue;
    dp(v, u);
    h[v] = f[v] + g[v][0];
    ans += f[u] * size[v] + size[u] * h[v];
    size[u] += size[v];
    f[u] += f[v] + g[v][0];
    for (long long j = 0; j < k; j++)
      for (long long t = 0; t < k; t++)
        if ((t + j) < k && j + 1 && t) ans -= g[u][t] * g[v][j];
    for (long long j = 0; j < k; j++) {
      long long to = (t + j) % k;
      g[u][to] += g[v][j];
    }
  }
  ans += f[u];
  g[u][0]++;
  size[u]++;
}
int main() {
  n = read(), k = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read();
    insert(x, y, 1);
  }
  dp(1, 0);
  printf("%lld\n", ans);
}
