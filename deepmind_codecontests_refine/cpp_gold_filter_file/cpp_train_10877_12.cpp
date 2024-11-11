#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 1e5 + 5;
int t, T, n, m, l[N], r[N], n1, n2, col[N];
vector<int> g[N];
void dfs(int x, int c) {
  if (col[x]) {
    if (col[x] ^ c) puts("IMPOSSIBLE"), exit(0);
    return;
  }
  col[x] = c;
  for (int y : g[x]) dfs(y, 3 - c);
}
signed main() {
  read(t);
  read(T);
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) read(l[i]), read(r[i]);
  n1 = *min_element(r + 1, r + 1 + n);
  n2 = *max_element(l + 1, l + 1 + n);
  if (n1 + n2 < t) n2 = t - n1;
  if (n1 + n2 > T) n1 = T - n2;
  if (n1 < 0 || n2 < 0) return puts("IMPOSSIBLE"), 0;
  for (int i = 1, x, y; i <= m; i++) {
    read(x);
    read(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    bool f1 = l[i] <= n1 && n1 <= r[i], f2 = l[i] <= n2 && n2 <= r[i];
    if (f1 && !f2)
      dfs(i, 1);
    else if (f2 && !f1)
      dfs(i, 2);
    else if (!f1 && !f2)
      return puts("IMPOSSIBLE"), 0;
  }
  for (int i = 1; i <= n; i++)
    if (!col[i]) dfs(i, 1);
  puts("POSSIBLE");
  write(n1);
  putchar(' ');
  write(n2);
  puts("");
  for (int i = 1; i <= n; i++) write(col[i]);
}
