#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int LG = 30, P = 1e9 + 7;
int a[LG], b[LG], c[LG];
pair<int, int> dp[LG][2][2][2];
int &Mod(int &first) { return first += (first >> 31) & P; }
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(Mod(a.first += b.first - P), Mod(a.second += b.second - P));
}
pair<int, int> DP(int n, int la, int lb, int lc) {
  if (n < 0) return make_pair(1, 0);
  if (dp[n][la][lb][lc] != make_pair(-1, -1)) return dp[n][la][lb][lc];
  int ma = la ? a[n] : 1, mb = lb ? b[n] : 1, mc = lc ? c[n] : 1;
  pair<int, int> &res = dp[n][la][lb][lc];
  res = make_pair(0, 0);
  for (int i = 0; i <= ma; i++) {
    for (int j = 0; j <= mb; j++) {
      if ((i ^ j) > mc) continue;
      pair<int, int> nxt =
          DP(n - 1, la && i == ma, lb && j == mb, lc && (i ^ j) == mc);
      res = res + nxt;
      if (i ^ j) Mod(res.second += ((long long)nxt.first << n) % P - P);
    }
  }
  return res;
}
int solve(int n, int m, int k) {
  memset(dp, -1, sizeof(dp));
  if (n < 0 || m < 0 || k < 0) return 0;
  for (int i = 0; i < LG; i++) {
    a[i] = (n & 1), n >>= 1;
    b[i] = (m & 1), m >>= 1;
    c[i] = (k & 1), k >>= 1;
  }
  pair<int, int> ans = DP(LG - 1, 1, 1, 1);
  return Mod(ans.first += ans.second - P);
}
int main() {
  int q;
  scanf("%d", &q);
  for (; q--;) {
    int u, d, l, r, k;
    scanf("%d%d%d%d%d", &u, &l, &d, &r, &k);
    u--, d--, l--, r--, k--;
    int res = 0;
    Mod(res += solve(d, r, k) - P);
    Mod(res -= solve(u - 1, r, k));
    Mod(res -= solve(d, l - 1, k));
    Mod(res += solve(u - 1, l - 1, k) - P);
    printf("%d\n", res);
  }
  return 0;
}
