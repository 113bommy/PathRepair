#include <bits/stdc++.h>
using namespace std;
const long long M = 500010, excess = 2;
string A;
long long dp[92][excess + 1][excess + 1];
long long f[92];
long long call(long long i, long long now, long long nxt) {
  if (i == A.size()) return now == 0 && nxt == 0;
  now += (A[i] == '1');
  if (now > excess || nxt > excess) return 0;
  if (dp[i][now][nxt] != -1) return dp[i][now][nxt];
  long long a = 0, b = 0;
  if (now > 0) a = call(i + 1, nxt + now - 1, now - 1);
  b = call(i + 1, nxt + now, now);
  return dp[i][now][nxt] = a + b;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long i, j, k;
  long long q, n;
  f[0] = 1;
  f[1] = 1;
  for (i = 2; i < 92; i++) f[i] = f[i - 1] + f[i - 2];
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &n);
    bool fg = false;
    for (i = 91; i > 0; i--) {
      if (n >= f[i]) {
        n -= f[i];
        fg = true;
        A += '1';
      } else if (fg)
        A += '0';
    }
    memset((dp), (-1), sizeof(dp));
    printf("%lld\n", call(0, 0, 0));
    A.clear();
  }
  return 0;
}
