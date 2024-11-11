#include <bits/stdc++.h>
using namespace std;
struct pat {
  int x, y;
  pat(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const pat &p) const { return x == p.x ? y < p.y : x < p.x; }
};
template <typename TP>
inline void read(TP &tar) {
  TP ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + (ch - '0');
    ch = getchar();
  }
  tar = ret * f;
}
template <typename TP, typename... Args>
inline void read(TP &t, Args &...args) {
  read(t), read(args...);
}
namespace RKK {
const int mo = 1000000007;
void doadd(int &a, const int &b) {
  if ((a += b) >= mo) a -= mo;
}
int add(const int &a, const int &b) { return a + b >= mo ? a + b - mo : a + b; }
int mul(const int &a, const int &b) { return (long long)a * b % mo; }
int n, ans;
int dp[34][34][2];
int main() {
  read(n);
  dp[32][0][1] = 1;
  for (int i = 32; i; i--)
    for (int j = 0; i + j <= 32; j++) {
      doadd(dp[i - 1][j][0], (dp[i][j][0] * (1ll << j)) % mo);
      doadd(dp[i - 1][j + 1][0], dp[i][j][0]);
      if (n >> i - 1 & 1) {
        doadd(dp[i - 1][j + 1][1], dp[i][j][1]);
        doadd(dp[i - 1][j][0], mul(dp[i][j][1], j ? 1ll << j - 1 : 1ll));
        doadd(dp[i - 1][j][1], mul(dp[i][j][1], j ? 1ll << j - 1 : 0ll));
      } else
        doadd(dp[i - 1][j][1], mul(dp[i][j][1], j ? 1ll << j - 1 : 1ll));
    }
  for (int i = 0; i <= 33; i++) doadd(ans, add(dp[0][i][0], dp[0][i][1]));
  printf("%lld\n", ans);
  return 0;
}
}  // namespace RKK
int main() { return RKK::main(); }
