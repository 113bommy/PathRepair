#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flg = true;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
const int mod = 1e9 + 7;
inline int upd(const int &x) { return x + (x >> 31 & mod); }
inline void add(int &x, const int &y) { x = upd(x + y - mod); }
inline void iadd(int &x, const int &y) { x = upd(x - y); }
int qpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod)
    if (y & 1) res = 1LL * res * x % mod;
  return res;
}
int fac[64], ifac[64];
void init(int x) {
  fac[0] = 1;
  for (int i(1), _i(x); i <= _i; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  ifac[x] = qpow(fac[x], mod - 2);
  for (int i(x), _i(1); i >= _i; i--) ifac[i - 1] = 1LL * ifac[i] * i % mod;
}
int n;
const int m = 60;
bool exst[64], vis[64];
void dfs(int x, vector<int> &S) {
  vis[x] = 1;
  S.push_back(x);
  for (int i = x + x; i <= m; i += x)
    if (exst[i] && !vis[i]) dfs(i, S);
  for (int i(1), _i(x - 1); i <= _i; i++)
    if (exst[i] && x % i == 0 && !vis[i]) dfs(i, S);
}
int work(const vector<int> &S) {
  static int id[64];
  int q = 0;
  static int msk[64];
  static int fwt[1 << 15];
  memset(id, -1, sizeof id);
  for (int x : S) {
    bool g = 0;
    for (int y : S)
      if (y < x && x % y == 0) {
        g = 1;
        break;
      }
    if (!g) id[x] = q++;
  }
  assert(q <= 15);
  const int lim = (1 << q) - 1;
  --q;
  for (int i(0), _i(lim); i <= _i; i++) fwt[i] = 0;
  for (int x : S)
    if (!~id[x]) {
      for (int y : S)
        if (x % y == 0 && ~id[y]) msk[x] |= 1 << id[y];
      ++fwt[msk[x]];
    }
  for (int j(0), _j(q); j <= _j; j++)
    for (int i(0), _i(lim); i <= _i; i++)
      if (i >> j & 1) fwt[i] += fwt[i ^ (1 << j)];
  static int dp[64][1 << 15];
  for (int i(0), _i(n); i <= _i; i++) memset(dp[i], 0, lim + 1 << 2);
  for (int x : S)
    if (!~id[x]) dp[1][msk[x]]++;
  for (int T(1), _T(lim); T <= _T; T++)
    for (int t(1), _t(n); t <= _t; t++)
      if (dp[t][T]) {
        const int &V = dp[t][T];
        if (fwt[T] - t > 0) add(dp[t + 1][T], 1LL * V * (fwt[T] - t) % mod);
        for (int x : S)
          if (!~id[x] && (msk[x] | T) != T && (msk[x] & T))
            add(dp[t + 1][msk[x] | T], V);
      }
  int mx = S.size() - q - 2;
  int z = 1LL * dp[mx][lim] * ifac[mx] % mod;
  return z;
}
void solve() {
  n = read();
  init(m + 2);
  for (int i(1), _i(n); i <= _i; i++) exst[read()] = 1;
  int z = n, ans = 1;
  for (int i(1), _i(m); i <= _i; i++)
    if (exst[i] && !vis[i]) {
      vector<int> S;
      dfs(i, S);
      sort((S).begin(), (S).end());
      if (S.size() == 1) continue;
      z--;
      ans = 1LL * ans * work(S) % mod;
    }
  for (int i(1), _i(m); i <= _i; i++)
    if (exst[i]) {
      bool g = 1;
      for (int j(1), _j(i - 1); j <= _j; j++)
        if (exst[j] && i % j == 0) {
          g = 0;
          break;
        }
      z -= g;
    }
  ans = 1LL * ans * fac[z] % mod;
  printf("%d\n", ans);
}
int main() {
  for (int T = 1; T--;) solve();
  return 0;
}
