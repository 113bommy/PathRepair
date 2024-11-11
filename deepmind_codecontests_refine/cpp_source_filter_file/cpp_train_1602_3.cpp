#include <bits/stdc++.h>
using namespace std;
struct point {
  int next, to;
} ar[350];
int a[350], head[350], art, dp[350], T[350], in[350], dp1[100050];
inline void read(int&), link(int, int), fmod(int&);
int main() {
  int n, q, t;
  read(n), read(q), read(t);
  for (int i(1); i <= n; ++i) read(a[i]), dp[i] = a[i];
  for (int i(1), u, v; i <= q; ++i) read(u), read(v), link(u, v), ++in[v];
  int L(0), R(0);
  for (int i(1); i <= n; ++i)
    if (!in[i]) T[++R] = i;
  while (L++ < R)
    for (int i(head[t -= dp[T[L]] - a[T[L]], T[L]]); i; i = ar[i].next) {
      if (dp[ar[i].to] += dp[T[L]], !(--in[ar[i].to])) T[++R] = ar[i].to;
      if (t < 0) return puts("0"), 0;
    }
  for (int i(1); i <= n; ++i)
    if (in[i]) return puts("0"), 0;
  for (int i(dp1[0] = 1), j; i <= n; ++i)
    for (j = dp[i]; j <= t; ++j) fmod(dp1[j] += dp1[j - dp[i]]);
  return printf("%d", (dp1[t] + 1000000007) % 1000000007), 0;
}
inline void fmod(int& x) { x < 0 ? x += 1000000007 : x -= 1000000007; }
inline void link(int u, int v) { ar[++art] = {head[u], v}, head[u] = art; }
inline void read(int& x) {
  x ^= x;
  register char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
}
