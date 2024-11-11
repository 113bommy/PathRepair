#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return ~f ? s : -s;
}
const int maxn = 5e3 + 20;
const long long inf = 1ll << 60;
int n, m;
int c[maxn], s[maxn], l[maxn];
inline void init() {
  n = read();
  m = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) l[i] = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) s[i] = read();
  for (int i = (1), _end_ = (n + m); i <= _end_; i++) c[i] = read();
}
long long dp[2020][maxn], LIM[maxn];
long long pre[2020][maxn];
inline long long solve(int x, int n, int st) {
  long long ans = 0;
  while (x && n) {
    ans += x * c[st];
    st++;
    x >>= 1;
    n--;
  }
  return ans;
}
struct Fenwick_Tree {
  long long s[2020];
  inline void Add(long long x, long long d) {
    for (; x <= m; x += x & (-x)) chkmax(s[x], d);
  }
  inline long long Sum(long long x) {
    long long res = -inf;
    for (; x; x -= x & (-x)) chkmax(res, s[x]);
    return res;
  }
} S[maxn];
inline void doing() {
  for (int i = (1), _end_ = (n); i <= _end_; i++) LIM[l[i]]++;
  for (int i = (1), _end_ = (n + m); i <= _end_; i++) LIM[i] += LIM[i - 1] >> 1;
  memset(dp, -63, sizeof(dp));
  memset(pre, -63, sizeof(pre));
  for (int i = (0), _end_ = (m); i <= _end_; i++)
    memset(S[i].s, -63, sizeof(S[i].s));
  dp[n + 1][0] = 0;
  long long ans = 0;
  for (int i = (n + 1), _end_ = (1); i >= _end_; i--) {
    int x = l[i];
    for (int j = (0), _end_ = (LIM[x]); j <= _end_; j++) {
      chkmax(dp[i][j], S[j].Sum(l[i]) - s[i]);
      chkmax(dp[i][j], pre[j][x] - s[i]);
      chkmax(ans, dp[i][j] + solve(j, 1000, x));
    }
    for (int j = (0), _end_ = (LIM[x]); j <= _end_; j++) {
      int x = j;
      long long dj = 0;
      long long L = l[i];
      while (x) {
        chkmax(pre[x + 1][L], dp[i][j] + dj);
        dj += x * c[L];
        L++;
        x >>= 1;
      }
      S[x + 1].Add(max(L, 1ll), dp[i][j] + dj);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  doing();
  return 0;
}
