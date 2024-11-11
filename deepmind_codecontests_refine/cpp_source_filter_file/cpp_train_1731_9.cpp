#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
const long long MAXN = 200001;
struct node {
  long long u, v, w;
} f[MAXN];
bool cmp(node x1, node x2) { return x1.w > x2.w; }
long long N, M, Ans;
struct Union {
  long long f[MAXN], d[MAXN];
  void init() {
    for (long long i = 1; i <= N; i++) f[i] = i;
    return;
  }
  long long getf(long long x) { return f[x] == x ? x : f[x] = getf(f[x]); }
  void merge(long long x, long long y) {
    long long t1 = getf(x), t2 = getf(y);
    f[t2] = t1, d[t2] |= d[t1];
  }
} U;
signed main() {
  N = read(), M = read();
  U.init();
  for (long long i = 1; i <= M; i++)
    f[i].u = read(), f[i].v = read(), f[i].w = read();
  sort(f + 1, f + M + 1, cmp);
  for (long long i = 1; i <= M; i++) {
    long long x = U.getf(f[i].u), y = U.getf(f[i].v);
    if (U.d[x] && U.d[y]) continue;
    if (x == y)
      U.merge(x, y), U.d[y] = 1;
    else
      U.merge(x, y);
    Ans += f[i].w;
  }
  printf("%lld\n", Ans);
  return 0;
}
