#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lowbit(T x) {
  return x & (-x);
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
inline T Pow(T a, T b, T p) {
  T ret = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) (ret *= a) %= p;
  return ret;
}
template <class T>
inline void read(T &ret) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  ret = x * f;
}
const int N = 3e5 + 10;
const long long Z = 998244353;
struct edge {
  int v, nxt;
} g[N * 2];
int head[N], sz = 0;
void add(int u, int v) {
  g[++sz] = {v, head[u]};
  head[u] = sz;
}
long long f[N][3];
void dfs(int u, int p) {
  f[u][0] = 0;
  f[u][1] = f[u][2] = 1;
  for (int i = head[u], v; i; i = g[i].nxt)
    if ((v = g[i].v) != p) {
      dfs(v, u);
      (f[u][1] *= 2 * f[v][0] + f[v][2]) %= Z;
      (f[u][2] *= f[v][0] + f[v][2]) %= Z;
    }
  for (int i = head[u], v; i; i = g[i].nxt)
    if ((v = g[i].v) != p) {
      long long inv = Pow(2 * f[v][0] + f[v][2], Z - 2, Z);
      (f[u][0] += f[u][1] * inv * f[v][1]) %= Z;
    }
}
int n;
int main() {
  read(n);
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    read(u);
    read(v);
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  printf("%lld", (f[1][0] + f[1][2]) % Z);
}
