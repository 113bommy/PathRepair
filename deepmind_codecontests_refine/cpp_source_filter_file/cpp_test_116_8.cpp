#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const long long linf = 1e18;
const int maxn = 5e5 + 9;
const int maxm = 1e5 + 9;
const double PI = 3.1415926;
const double eps = 1e-5;
const int base = 131;
const int N = 1e6;
const long long mod = 998244353;
namespace IO {
long long read() {
  long long a = 1, b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') a = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    b = (b << 3) + (b << 1) + c - '0';
    c = getchar();
  }
  return a * b;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace IO
using namespace IO;
int n;
int dp[maxn][2];
int main() {
  int cse = read();
  while (cse--) {
    dp[0][0] = 1;
    n = read();
    for (int i = 1; i <= n; ++i) {
      int x = read() + 1;
      dp[x][0] += dp[x - 1][0] + dp[x][0];
      dp[x][1] += dp[x][1];
      if (x > 1) dp[x][1] += dp[x - 2][0];
      dp[x + 2][1] += dp[x + 2][1];
      dp[x][0] %= mod;
      dp[x][1] %= mod;
      dp[x + 2][1] %= mod;
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
      ans = (ans + dp[i][0] + dp[i][1]) % mod;
    }
    print(ans);
    putchar('\n');
    for (int i = 0; i <= n + 1; ++i) dp[i][0] = dp[i][1] = 0;
  }
  return 0;
}
