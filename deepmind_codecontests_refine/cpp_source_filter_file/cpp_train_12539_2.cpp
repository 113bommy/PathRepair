#include <bits/stdc++.h>
namespace chtholly {
char buf[1 << 23], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return f ? x : -x;
}
template <typename mitsuha>
inline bool read(mitsuha &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c) && ~c; c = getchar()) f ^= c == '-';
  if (!~c) return 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return x = f ? x : -x, 1;
}
template <typename mitsuha>
inline int write(mitsuha x) {
  if (!x) return 0 & putchar(48);
  if (x < 0) putchar('-'), x = -x;
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
  return 0;
}
inline char fuhao() {
  char c = getchar();
  for (; isspace(c); c = getchar())
    ;
  return c;
}
}  // namespace chtholly
using namespace chtholly;
using namespace std;
const int yuzu = 1e5;
typedef int fuko[yuzu | 10];
vector<int> lj[yuzu | 10], ph;
fuko tov, vis;
void dfs(int u, int fa = 0) {
  vis[u] = 1, ph.push_back(u), tov[u] ^= 1;
  for (int v : lj[u])
    if (!vis[v]) dfs(v, u), ph.push_back(u), tov[u] ^= 1;
  if (tov[u] && fa)
    ph.push_back(fa), tov[fa] ^= 1, ph.push_back(u), tov[u] ^= 1;
  if (tov[u]) ph.pop_back();
}
bool judge(int n) {
  int i, hoc = 0;
  static fuko vs;
  for (i = 1; i <= n; ++i)
    if (!vs[i]) {
      int bo = 0;
      queue<int> q;
      vs[i] = 1, q.push(i);
      for (; !q.empty();) {
        int u = q.front();
        q.pop();
        if (tov[i]) bo = 1;
        for (int v : lj[u])
          if (!vs[v]) vs[v] = 1, q.push(v);
      }
      hoc += bo;
    }
  return hoc <= 1;
}
int main() {
  int i, n, m, u, v;
  read(n), read(m);
  for (i = 1; i <= m; ++i)
    u = read(), v = read(), lj[u].push_back(v), lj[v].push_back(u);
  for (i = 1; i <= n; ++i) tov[i] = read();
  if (!judge(n)) return puts("-1"), 0;
  for (i = 1; i <= n; ++i)
    if (!vis[i] && tov[i]) dfs(i);
  cout << ph.size() << endl;
  for (auto p : ph) write(p), putchar(' ');
}
