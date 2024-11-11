#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline char ch() {
  static char s[1 << 16], *S, *T;
  return (S == T) && (T = (S = s) + fread(s, 1, 1 << 16, stdin), S == T) ? EOF
                                                                         : *S++;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f(1);
  char c = ch();
  for (; !isdigit(c); c = ch())
    if (c == '-') f = -1;
  for (; isdigit(c); c = ch()) x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
}  // namespace IO
using namespace IO;
const int maxn = 100005;
int n, K, A[maxn], cnt[maxn];
long long dp[2][maxn], nw;
void Solve(int p, int l, int r, int L, int R, long long w) {
  if (l > r) return;
  int mid = (l + r) >> 1, k = 0, q = mid < R ? mid : R;
  for (int i = l; i <= mid; ++i) w += cnt[A[i]]++;
  for (int i = L; i <= q; ++i) {
    w -= --cnt[A[i]];
    if (dp[p][mid] > dp[p ^ 1][i] + w) dp[p][mid] = dp[p ^ 1][i] + w, k = i;
  }
  for (int i = L; i <= q; ++i) w += cnt[A[i]]++;
  for (int i = l; i <= mid; ++i) w -= --cnt[A[i]];
  Solve(p, l, mid - 1, L, k, w);
  for (int i = l; i <= mid; ++i) w += cnt[A[i]]++;
  for (int i = L; i < k; ++i) w -= --cnt[A[i]];
  Solve(p, mid + 1, r, k, R, w);
  for (int i = L; i < k; ++i) ++cnt[A[i]];
  for (int i = l; i <= mid; ++i) --cnt[A[i]];
}
int main() {
  read(n, K);
  for (int i(1); i <= n; ++i) {
    read(A[i]);
    nw += cnt[A[i]]++;
    dp[0][i] = nw;
  }
  memset(cnt, 0, sizeof cnt);
  nw = 0;
  for (int i(1); i < K; ++i) {
    for (int j(1); j <= n; ++j) dp[i & 1][j] = 1e16 + 7;
    Solve(i & 1, 1, n, 1, n, 0);
  }
  cout << dp[(K - 1) & 1][n] << endl;
  return 0;
}
