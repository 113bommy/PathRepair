#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  char ch;
  x = 0;
  bool fl = false;
  while (!isdigit(ch = getchar())) (ch == '-') && (fl = true);
  for (x = (ch ^ '0'); isdigit(ch = getchar()); x = x * 10 + (ch ^ '0'))
    ;
  (fl == true) && (x = -x);
}
template <class T>
inline void output(T x) {
  if (x / 10) output(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void ot(T x) {
  if (x < 0) putchar('-'), x = -x;
  output(x);
  putchar(' ');
}
template <class T>
inline void prt(T a[], int st, int nd) {
  for (register int i = st; i <= nd; ++i) ot(a[i]);
  putchar('\n');
}
namespace Modulo {
const int mod = 998244353;
int ad(int x, int y) { return (x + y) >= mod ? x + y - mod : x + y; }
void inc(int &x, int y) { x = ad(x, y); }
int mul(int x, int y) { return (long long)x * y % mod; }
void inc2(int &x, int y) { x = mul(x, y); }
int qm(int x, int y = mod - 2) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = mul(x, ret);
    x = mul(x, x);
    y >>= 1;
  }
  return ret;
}
}  // namespace Modulo
namespace Miracle {
const int N = 300000 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
int du[N];
int b[N][2];
vector<int> to[N];
int go[N];
int q[N], l, r, df;
void topo() {
  l = 1, r = 0;
  df = 0;
  for (register int i = 1; i <= n; ++i) {
    if (du[i] == 0) q[++r] = i;
  }
  while (l <= r) {
    int x = q[l];
    ++df;
    int sz = r - l + 1;
    ++l;
    if (sz == 1) {
      go[x] += n - df;
    } else if (sz == 2) {
      int b = q[l];
      int lp = 0;
      for (const auto &y : to[b]) {
        if (du[y] == 1) {
          ++lp;
          break;
        }
      }
      if (!lp) go[x] += n - df - 1 - lp;
    }
    for (const auto &y : to[x]) {
      --du[y];
      if (du[y] == 0) {
        q[++r] = y;
      }
    }
  }
}
int main() {
  rd(n);
  rd(m);
  for (register int i = 1; i <= m; ++i) {
    rd(b[i][0]);
    rd(b[i][1]);
    to[b[i][0]].push_back(b[i][1]);
    ++du[b[i][1]];
  }
  topo();
  for (register int i = 1; i <= n; ++i) to[i].clear(), du[i] = 0;
  for (register int i = 1; i <= m; ++i) {
    to[b[i][1]].push_back(b[i][0]);
    ++du[b[i][0]];
  }
  topo();
  int ans = 0;
  for (register int i = 1; i <= n; ++i) {
    if (go[i] >= n - 2) ++ans;
  }
  ot(ans);
  return 0;
}
}  // namespace Miracle
signed main() {
  Miracle::main();
  return 0;
}
