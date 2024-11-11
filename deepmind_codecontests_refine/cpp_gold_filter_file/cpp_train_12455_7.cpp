#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, MAX = 2e6 + 7;
int pw[MAX], dp[MAX];
int fpow(int b, int p) {
  long long int r = 1ll;
  for (int i = (32 - __builtin_clz(p)); i >= (0); --i) {
    r *= r;
    r %= P;
    if (p & (1 << i)) {
      r *= b;
      r %= P;
    }
  }
  return int(r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = (1); i <= (k); ++i) pw[i] = fpow(i, n);
  long long int ans = 0ll, sum = 0ll;
  for (int i = (1); i <= (k); ++i) {
    dp[i] += pw[i] - pw[i - 1];
    if (dp[i] >= P) dp[i] -= P;
    if (dp[i] < 0) dp[i] += P;
    sum += dp[i];
    if (sum >= P) sum -= P;
    ans += (sum ^ i);
    if (ans >= P) ans -= P;
    for (int j = 2 * i; j <= k; j += i) {
      dp[j] -= dp[i];
      if (dp[j] < 0) dp[j] += P;
    }
  }
  cout << ans << '\n';
  return 0;
}
