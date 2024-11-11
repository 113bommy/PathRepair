#include <bits/stdc++.h>
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T& t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n, K;
int a[1100000];
int ppc[1100000], to[1100000];
int mat[1100000], inR[1100000];
int ans;
int in[1100000];
vector<int> V2;
int mx[1100000], pre[1100000];
void dfs(int x) {
  if (mat[x] == -1) return;
  for (int i = (0); i <= (n - 1); i++)
    if (in[1 << i ^ mat[x]] && chkmax(mx[1 << i ^ mat[x]], mx[x]))
      pre[1 << i ^ mat[x]] = x, dfs(1 << i ^ mat[x]);
}
int work(int _w) {
  for (auto x : V2) mx[x] = -1e7, pre[x] = -1;
  for (auto x : V2)
    for (int i = (0); i <= (n - 1); i++)
      if (!inR[1 << i ^ x] && chkmax(mx[x], a[1 << i ^ x])) pre[x] = 1 << i ^ x;
  sort(V2.begin(), V2.end(), [](int x, int y) { return mx[x] > mx[y]; });
  for (auto x : V2) dfs(x);
  int _mx = -1, X = -1;
  for (auto x : V2)
    if (mat[x] == -1 && chkmax(_mx, a[x] + mx[x])) X = x;
  if (_mx <= _w) return 0;
  ans += _mx;
  while (ppc[pre[X]] & 1) mat[X] = mat[pre[X]], X = pre[X];
  inR[pre[X]] = 1, mat[X] = pre[X];
  for (int i = (0); i <= (n - 1); i++)
    if (chkmax(in[1 << i ^ mat[X]], 1)) V2.push_back(1 << i ^ mat[X]);
  return 1;
}
void Assert(int x) {
  static int ti;
  ++ti;
  if (!x) exit((cout << ti, 0));
}
int main() {
  file();
  read(n, K);
  for (int i = (0); i <= ((1 << n) - 1); i++)
    read(a[i]), ppc[i] = __builtin_popcount(i);
  priority_queue<pair<int, int> > q;
  for (int x = (0); x <= ((1 << n) - 1); x++)
    if (ppc[x] & 1) {
      int mx = -1;
      for (int i = (0); i <= (n - 1); i++)
        if (chkmax(mx, a[1 << i ^ x])) to[x] = 1 << i ^ x;
      q.push(make_pair(mx + a[x], x));
    }
  memset(mat, -1, sizeof(mat));
  chkmin(K, 1 << (n - 1));
  for (int _ = (1); _ <= (K); _++) {
    int mx = -1;
    while (q.size() && in[q.top().second]) q.pop();
    if (q.size()) mx = q.top().first;
    if (!work(mx)) {
      ans += mx;
      int x = q.top().second, y = to[x];
      mat[x] = y, inR[y] = 1;
      for (int i = (0); i <= (n - 1); i++)
        if (chkmax(in[1 << i ^ y], 1)) V2.push_back(1 << i ^ y);
    }
  }
  int c = 0;
  long long sum = 0;
  static int ti[1100000];
  for (int i = (0); i <= ((1 << n) - 1); i++)
    if ((ppc[i] & 1) && mat[i] != -1)
      ++c, ++ti[mat[i]], Assert(inR[mat[i]]), Assert(in[i]),
          Assert(ti[mat[i]] == 1), Assert(ppc[i ^ mat[i]] == 1),
          sum += a[i] + a[mat[i]];
  Assert(c == K), Assert(sum == ans);
  cout << ans;
  return 0;
}
