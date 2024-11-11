#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
template <class T>
inline void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
}
struct edge {
  int next, to;
} e[N << 1];
int t, T, n, m, cnt, head[N], l[N], r[N], co[N], n1 = 0x3f3f3f3f, n2;
inline void add(int u, int v) {
  e[++cnt] = {head[u], v};
  head[u] = cnt;
}
void dfs(int x) {
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (!co[y])
      co[y] = 3 - co[x], dfs(y);
    else if (co[y] == co[x])
      puts("IMPOSSIBLE"), exit(0);
  }
}
int main() {
  read(t), read(T), read(n), read(m);
  for (int i = 1; i <= n; i++)
    read(l[i]), read(r[i]), n1 = min(n1, r[i]), n2 = max(n2, l[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u), read(v);
    add(u, v), add(v, u);
  }
  if (n1 + n2 < t) n2 = t - n1;
  if (n1 + n2 > T) n1 = T - n2;
  if (n1 < 0 || n2 < 0) return puts("IMPOSSIBLE"), 0;
  for (int i = 1; i <= n; i++)
    if (l[i] <= n1 && r[i] >= n1 && (l[i] > n2 || r[i] < n2))
      co[i] = 1;
    else if (l[i] <= n2 && r[i] >= n2 && (l[i] > n1 || r[i] < n1))
      co[i] = 2;
    else if ((l[i] > n1 || r[i] < n1) && (l[i] > n2 || r[i] < n2))
      return puts("IMPOSSIBLE"), 0;
  for (int i = 1; i <= n; i++)
    if (co[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (!co[i]) co[i] = 1, dfs(1);
  puts("POSSIBLE");
  printf("%d %d\n", n1, n2);
  for (int i = 1; i <= n; i++) (co[i] - 1) ? putchar('2') : putchar('1');
  return 0;
}
