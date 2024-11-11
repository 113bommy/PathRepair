#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[5005][5005];
long long GET(int h) {
  long long res = 1;
  long long cur = 2;
  for (int i = 0; i <= 14; ++i) {
    if ((h >> i) & 1) res = res * cur % 1000000007;
    cur = cur * cur % 1000000007;
  }
  return res;
}
long long df(int diff, int a) {
  if (dp[diff][a]) return dp[diff][a];
  int b = n - a;
  if (!diff) return dp[diff][a] = GET(b);
  return dp[diff][a] =
             ((a ? 1ll * a * df(diff - 1, a) % 1000000007 : 0ll) +
              (b ? 1ll * b * df(diff - 1, a + 1) % 1000000007 : 0ll)) %
             1000000007;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  cout << df(k, 0);
}
