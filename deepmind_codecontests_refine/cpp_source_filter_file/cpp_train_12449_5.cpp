#include <bits/stdc++.h>
using namespace std;
const int N = 17;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int d[N], top;
int dp[N][N][1 << 16];
long long DP(int n, int j, int s, bool full) {
  if (n == 0) return (s >> j) & 1;
  if (!full && dp[n][j][s] != -1) return dp[n][j][s];
  long long ret = 0;
  int rbd = (full ? d[n] : 15);
  for (int i = 0; i <= rbd; ++i) {
    int vs = s;
    if (n <= 4) vs |= (i << ((n - 1) << 2));
    ret += DP(n - 1, max(j, i), vs, full && (i == rbd));
  }
  if (!full) dp[n][j][s] = ret;
  return ret;
}
long long Calc(long long x) {
  if (x <= 0) return 0;
  top = 0;
  while (x) {
    d[++top] = x & 15;
    x >>= 4;
  }
  return DP(top, 0, 0, 1);
}
void solve() {
  cin.tie(0);
  int q;
  read(q);
  memset(dp, -1, sizeof(dp));
  while (q--) {
    long long l, r;
    cin >> hex >> l;
    cin >> hex >> r;
    printf("%lld\n", Calc(r) - Calc(l - 1));
  }
}
int main() {
  solve();
  return 0;
}
