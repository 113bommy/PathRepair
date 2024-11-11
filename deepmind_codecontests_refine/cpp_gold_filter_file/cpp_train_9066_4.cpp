#include <bits/stdc++.h>
using namespace std;
namespace my_std {
const int inf = 0x3f3f3f3f;
const long long inff = 1e15;
inline int read() {
  int sum = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = sum * 10 + (ch ^ 48);
    ch = getchar();
  }
  return sum * f;
}
inline void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  putchar('\n');
}
inline void writesp(int x) {
  write(x);
  putchar(' ');
}
}  // namespace my_std
using namespace my_std;
const int N = 1e5 + 50;
int n, B, idx, f[N], fat[N], dfn[N], head[N], cnt, ans[N];
struct edge {
  int to, nxt;
} e[N << 1];
inline void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
void dfs(int u, int fa) {
  fat[u] = fa;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != fa) dfs(v, u);
  }
  dfn[++idx] = u;
}
inline int solve(int k) {
  int ans = 0;
  for (register int i = (1); i <= (n); ++i) f[i] = 1;
  for (register int i = (1); i <= (n); ++i) {
    int u = dfn[i];
    if (fat[u] && f[fat[u]] && f[u]) {
      if (f[u] + f[fat[u]] >= k) {
        ++ans, f[fat[u]] = 0;
      } else
        f[fat[u]] = max(f[fat[u]], f[u] + 1);
    }
  }
  return ans;
}
int main(void) {
  n = read();
  B = sqrt(n * log(n) / log(2));
  for (register int i = (1); i <= (n - 1); ++i) {
    int u = read(), v = read();
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  ans[1] = n;
  for (register int i = (2); i <= (B); ++i) ans[i] = solve(i);
  for (int i = B + 1, l, r; i <= n; i = l + 1) {
    l = i, r = n;
    int tmp = solve(i);
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (solve(mid) == tmp)
        l = mid;
      else
        r = mid;
    }
    for (register int j = (i); j <= (l); ++j) ans[j] = tmp;
  }
  for (register int i = (1); i <= (n); ++i) writeln(ans[i]);
  return 0;
}
