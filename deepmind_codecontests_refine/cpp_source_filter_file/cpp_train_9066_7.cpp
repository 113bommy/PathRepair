#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline int read() {
  int x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
void File() {}
const int N = 1e5 + 1e3, inf = 0x3f3f3f3f;
int n, f[N], ans, k;
vector<int> G[N];
void Dp(int u = 1, int fa = 0) {
  f[u] = 1;
  bool flag = true;
  for (int v : G[u])
    if (v != fa) {
      Dp(v, u);
      if ((f[u] + f[v]) >= k) f[u] = 0, ++ans, flag = false;
      if (flag) chkmax(f[u], f[v] + 1);
    }
  if (f[u] >= k) f[u] = 0, ++ans;
}
inline int Calc(int lim) {
  k = lim;
  ans = 0;
  Dp();
  return ans;
}
void Solve(int l, int r, int vl, int vr) {
  if (l > r) return;
  if (vl == vr) {
    for (register int i = (l), iend = (int)(r); i <= iend; ++i)
      printf("%d\n", vl);
    return;
  }
  int mid = (l + r) >> 1, res = Calc(mid);
  Solve(l, mid - 1, vl, res);
  printf("%d\n", res);
  Solve(mid + 1, r, res, vr);
}
int main() {
  File();
  n = read();
  for (register int i = (1), iend = (int)(n - 1); i <= iend; ++i) {
    int u = read(), v = read();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  Solve(1, n, 0, n);
  return 0;
}
