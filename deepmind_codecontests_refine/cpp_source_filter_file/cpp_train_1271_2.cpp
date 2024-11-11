#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') f = -1;
  } while (c < '0' || c > '9');
  do {
    x = x * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return f * x;
}
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
bool umin(long long &a, long long b) {
  if (b < a) return a = b, 1;
  return 0;
}
bool umax(long long &a, long long b) {
  if (b > a) return a = b, 1;
  return 0;
}
struct Edge {
  long long v, nxt;
} e[3011 << 1 | 1];
long long cnt = 0, last[3011];
void adde(long long u, long long v) {
  e[++cnt].v = v;
  e[cnt].nxt = last[u], last[u] = cnt;
}
long long a[3011], size[3011];
std::pair<long long, long long> f[3011][3011], tmp[3011];
void upd(std::pair<long long, long long> &a,
         std::pair<long long, long long> t) {
  if (t > a) a = t;
}
void dp(long long u, long long fa = 0) {
  size[u] = 1;
  f[u][1] = std::pair<long long, long long>(0, a[u]);
  for (long long i = last[u]; i; i = e[i].nxt) {
    long long v = e[i].v;
    if (v == fa) continue;
    dp(v, u);
    for (long long j = 1; j <= size[u] + size[v]; ++j)
      tmp[j] = std::pair<long long, long long>(0, 0);
    for (long long j = 1; j <= size[u]; ++j)
      for (long long k = 1; k <= size[v]; ++k) {
        upd(tmp[j + k],
            std::pair<long long, long long>(
                f[u][j].first + f[v][k].first + (f[v][k].second > 0),
                f[u][j].second));
        upd(tmp[j + k - 1],
            std::pair<long long, long long>(f[u][j].first + f[v][k].first,
                                            f[u][j].second + f[v][k].second));
      }
    for (long long j = 1; j <= size[u] + size[v]; ++j) f[u][j] = tmp[j];
    size[u] += size[v];
  }
}
int main() {
  long long task = read();
  while (task--) {
    long long n = read(), m = read();
    for (long long i = 1; i <= n; ++i) a[i] = -read();
    for (long long i = 1; i <= n; ++i) a[i] += read();
    for (long long i = 1; i < n; ++i) {
      long long u = read(), v = read();
      adde(u, v), adde(v, u);
    }
    dp(1);
    printf("%lld\n", f[1][m].first + (f[1][m].second > 0));
    cnt = 0;
    for (long long i = 1; i <= n; ++i) {
      last[i] = 0;
      for (long long j = 1; j <= m; ++j)
        f[i][j] = std::pair<long long, long long>(0, 0);
    }
  }
  return 0;
}
