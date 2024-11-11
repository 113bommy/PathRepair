#include <bits/stdc++.h>
using namespace std;
namespace Sweet {
template <typename T>
inline void read(T &x) {
  static char ch;
  int f = 1;
  while (ch = getchar(), ch > '9' || ch < '0') (ch == '-') && (f = -1);
  x = (ch ^ 48);
  while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48);
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
template <typename T>
inline void write(T x) {
  static int stk[100], top = 0;
  if (x == 0) return (void)putchar('0');
  if (x < 0) x = -x, putchar('-');
  while (x) stk[++top] = x % 10, x /= 10;
  while (top) putchar(stk[top--] + '0');
}
const int N = 2e6 + 10;
int tot, head[N];
struct E {
  int next, to;
} e[N];
inline void add(int x, int y) { e[++tot] = (E){head[x], y}, head[x] = tot; }
int fa[N], sz[N];
double f[N];
void dfs(int x) {
  sz[x] = 1;
  for (int i = head[x], v; i; i = e[i].next) {
    dfs(v = e[i].to), sz[x] += sz[v];
  }
}
void dfs1(int x) {
  for (int i = head[x], v; i; i = e[i].next) {
    v = e[i].to, f[v] = f[x] + 1 + (sz[x] - sz[v] - 1) / 2.0, dfs1(v);
  }
}
int n;
inline void main() {
  read(n);
  for (int i = 2; i <= n; ++i) read(fa[i]), add(fa[i], i);
  f[1] = 1, dfs(1), dfs1(1);
  for (int i = 1; i <= n; ++i) printf("%.7lf ", f[i]);
}
}  // namespace Sweet
int main() {
  Sweet::main();
  return 0;
}
