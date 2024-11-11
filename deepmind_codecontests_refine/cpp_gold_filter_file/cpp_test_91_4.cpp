#include <bits/stdc++.h>
using namespace std;
namespace Ruri {
const int infi = 1e9;
const long long infl = 4e18;
}  // namespace Ruri
using namespace Ruri;
namespace Gadgets {
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
inline long long pos_mod(long long a, long long b) { return (a % b + b) % b; }
}  // namespace Gadgets
namespace Read {
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long rl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double rd() {
  double x;
  scanf("%lf", &x);
  return x;
}
}  // namespace Read
namespace DeBug {}
using namespace Gadgets;
using namespace Read;
using namespace DeBug;
const int MAX_N = 1e5 + 5;
const int mod = 998244353;
void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void Minus(int &x, int y) {
  x -= y;
  x += (x >> 31) & mod;
};
void Mul(int &x, int y) { x = 1ll * x * y % mod; }
int n, a[MAX_N];
int dp[2][MAX_N];
int main() {
  int T = ri();
  while (T--) {
    n = ri();
    for (int i = 1, bbb = n; i <= bbb; ++i) a[i] = ri();
    int ans = 0;
    int now = 1, pre = 0;
    dp[pre][a[n]] = 1;
    for (int i = n, bbb = 1; i >= bbb; --i) {
      for (int l = 1, r; l <= a[i]; l = r + 1) {
        r = a[i] / (a[i] / l), dp[now][a[i] / r] = 0;
      }
      Add(dp[now][a[i]], 1);
      if (i == n) {
        swap(pre, now);
        continue;
      }
      for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
        r = a[i + 1] / (a[i + 1] / l);
        int val = a[i + 1] / r;
        if (dp[pre][val]) {
          if (false)
            cout << "dp[pre][val]"
                 << ": " << (dp[pre][val]) << endl;
          ;
          if (false)
            cout << "val"
                 << ": " << (val) << endl;
          ;
          int k = ceil_div(a[i], val), res = i;
          Mul(res, 1ll * (k - 1) * dp[pre][val] % mod);
          Add(ans, res);
          Add(dp[now][a[i] / k], dp[pre][val]);
        }
      }
      swap(pre, now);
    }
    if (false)
      cout << "ans"
           << ": " << (ans) << endl;
    ;
    printf("%lld\n", pos_mod(ans, mod));
  }
  return 0;
}
