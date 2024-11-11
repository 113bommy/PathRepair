#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 2e6 + 9;
int head[N], nex[N], to[N], w[N], cnt;
inline void add(int u, int v, int c) {
  nex[++cnt] = head[u];
  head[u] = cnt, to[cnt] = v, w[cnt] = c;
}
int n, siz[N];
long long mn, mx;
inline void dfs(int u, int _f) {
  siz[u] = 1;
  for (int i = head[u]; i; i = nex[i])
    if (to[i] ^ _f) {
      dfs(to[i], u), siz[u] += siz[to[i]];
      mn += (siz[to[i]] & 1 ? w[i] : 0),
          mx += min(siz[to[i]], n - siz[to[i]]) * w[i];
    }
}
int main() {
  int T = read<int>();
  while (T--) {
    n = 2 * read<int>();
    for (int i = 1; i <= n; i++) head[i] = 0;
    cnt = 0;
    for (int i = 1; i < n; i++) {
      int u = read<int>(), v = read<int>(), c = read<int>();
      add(u, v, c), add(v, u, c);
    }
    mn = 0, mx = 0, dfs(1, 0);
    printf("%lld %lld\n", mn, mx);
  }
  return 0;
}
}  // namespace run
int main() { return run::main(); }
