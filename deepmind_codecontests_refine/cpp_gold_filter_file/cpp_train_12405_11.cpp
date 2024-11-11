#include <bits/stdc++.h>
using namespace std;
long long read(long long x = 0) {
  int c, f = 1;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return f * x;
}
long long f[400010], frac[400010], N;
struct Graph {
  int etot, head[400010], to[400010], next[400010], N;
  void clear() {
    int i;
    for (i = 1; i <= N; i++) head[i] = 0;
    for (i = 1; i <= etot; i++) to[i] = next[i] = 0;
    N = etot = 0;
  }
  void adde(int a, int b) {
    to[++etot] = b;
    next[etot] = head[a];
    head[a] = etot;
  }
} G;
void dfs(long long pos, long long pre) {
  long long p, sub(0);
  f[pos] = 1;
  for (p = G.head[pos]; p; p = G.next[p])
    if (G.to[p] != pre) {
      sub++;
      dfs(G.to[p], pos);
      f[pos] = f[pos] * f[G.to[p]] % 998244353ll;
    }
  f[pos] = f[pos] * frac[sub] % 998244353ll;
  if (pos != 1) f[pos] = f[pos] * (sub + 1) % 998244353ll;
}
int main() {
  long long i, j, l, r, mid, pos, a, b;
  N = read();
  G.N = N;
  for (i = 1; i < N; i++) {
    a = read(), b = read();
    G.adde(a, b);
    G.adde(b, a);
  }
  frac[0] = 1ll;
  for (i = 1; i <= N; i++) frac[i] = frac[i - 1] * i % 998244353ll;
  dfs(1, 0);
  printf("%lld", f[1] * N % 998244353ll);
  return 0;
}
