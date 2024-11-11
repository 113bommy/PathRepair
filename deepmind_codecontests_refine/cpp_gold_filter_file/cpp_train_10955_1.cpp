#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int N = 200010;
const int M = 200010;
const int P = 1000000007;
const int Inf = 1000000007;
const int Fni = -1000000007;
inline int qr() {
  int r = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    r = (r << 1) + (r << 3) + c - '0', c = getchar();
  }
  return r * f;
}
template <typename T>
void debug(T x, char c = '\n') {
  cerr << x << c;
}
template <typename T>
void debug(T *const tp, int minn, int maxn, char v = ' ', char c = '\n') {
  for (int i = minn; i <= maxn; ++i) debug(tp[i], v);
  cerr << c;
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
inline void add(T &x, long long y, int mod = P) {
  x += y;
  x = x >= mod ? x - mod : x;
}
template <typename T>
inline void dec(T &x, long long y, int mod = P) {
  x -= y;
  x = x < 0 ? x + mod : x;
}
template <typename T>
inline T addn(T x, long long y, int mod = P) {
  x += y;
  return (x = x > mod ? x - mod : x);
}
template <typename T>
inline T decn(T x, long long y, int mod = P) {
  x -= y;
  return (x = x < 0 ? x + mod : x);
}
int ans;
int res1;
int res2;
int root;
int T, n;
int buc[N];
int deg[N];
int dep[N];
vector<int> E[N];
void dfs(int x, int y) {
  int qwq = 0;
  dep[x] = dep[y] + 1;
  for (auto k : E[x])
    if (k != y) {
      dfs(k, x);
      qwq += (deg[k] <= 1);
    }
  if (qwq > 1) res2 -= qwq - 1;
  if (deg[x] == 1 && x != root) ans = ans & (dep[x] & 1), buc[dep[x]]++;
}
int main() {
  cin >> n;
  int x, y;
  ans = 1;
  for (int i = 1; i < n; ++i) {
    x = qr(), y = qr();
    deg[x]++, deg[y]++;
    E[x].push_back(y), E[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] <= 1) root = i;
  dfs(root, 0);
  res2 += n - 1;
  res1 = 1 + 2 * (!ans);
  if (buc[3]) res2--;
  cout << res1 << " " << res2 << '\n';
  return 0;
}
