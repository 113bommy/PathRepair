#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T x = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 3e5 + 9, mod = 998244353;
inline int add(int x, int y) { return x + y >= mod ? x - mod + y : x + y; }
inline int sub(int x, int y) { return x >= y ? x - y : x + mod - y; }
int head[N], nex[N << 1], to[N << 1], cnt;
inline void adde(int u, int v) {
  nex[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
int f[N][3], n;
inline void dfs(int u, int _f) {
  f[u][0] = f[u][1] = f[u][2] = 1;
  for (int i = head[u]; i; i = nex[i])
    if (to[i] ^ _f) {
      dfs(to[i], u);
      f[u][0] = 1LL * f[u][0] *
                sub(add(2LL * f[to[i]][0] % mod, 2LL * f[to[i]][1] % mod),
                    f[to[i]][2]) %
                mod;
      f[u][1] = 1LL * f[u][1] *
                sub(add(2LL * f[to[i]][0] % mod, f[to[i]][1]), f[to[i]][2]) %
                mod;
      f[u][2] =
          1LL * f[u][2] * sub(add(f[to[i]][0], f[to[i]][1]), f[to[i]][2]) % mod;
    }
}
int main() {
  n = read<int>();
  for (int i = 1; i < n; i++) {
    int u = read<int>(), v = read<int>();
    adde(u, v), adde(v, u);
  }
  dfs(1, 0);
  printf("%d\n", sub(add(f[1][0], f[1][1]), add(f[1][2], 1)));
  return 0;
}
}  // namespace run
int main() { return run::main(); }
