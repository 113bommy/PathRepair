#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, cnt;
int head[N], siz[N];
int val[N];
struct edge {
  int to, nxt;
} e[N << 1];
inline int read() {
  int x = 0, op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * op;
}
inline void add(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
inline void dfs(int u, int fa, int dep) {
  siz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u, dep + 1);
    siz[u] += siz[v];
  }
  val[u] = dep - (siz[u] - 1);
}
int main() {
  n = read(), k = read();
  for (int i = 1, x, y; i <= n - 1; ++i) {
    x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, -1, 0);
  long long ans = 0;
  sort(val + 1, val + 1 + n);
  for (int i = 0; i < k; i++) {
    ans += val[n - i];
  }
  printf("%lld\n", ans);
  return 0;
}
