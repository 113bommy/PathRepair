#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
template <class T>
inline bool RD(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1, ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void PT(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) PT(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 10;
int dp[N][303];
int a[N], b[N];
vector<int> vec[N];
int main() {
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i) RD(a[i]);
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i)
    RD(b[i]), vec[b[i]].push_back(i);
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i)
    vec[a[i]].push_back(INF + 1);
  memset(dp, 0x3f, sizeof(dp));
  int K = s / e;
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  int ans = 0;
  for (int k = 1; k <= K; k++)
    for (int i = 1; i <= n; i++) {
      int tmp =
          min(dp[i - 1][k], *upper_bound((vec[a[i]]).begin(), (vec[a[i]]).end(),
                                         dp[i - 1][k - 1]));
      if (tmp < INF) {
        dp[i][k] = tmp;
        ans = max(ans, k * (s - k * e >= i + dp[i][k]));
      }
    }
  printf("%d\n", ans);
}
