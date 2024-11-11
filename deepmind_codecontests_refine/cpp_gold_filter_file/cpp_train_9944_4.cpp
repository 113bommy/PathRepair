#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 1000005;
long long n, a, b;
long long cost[maxn], val[maxn], dp[maxn][3];
vector<long long> gcd;
long long cal(long long x) {
  int i;
  for (i = 1; i <= n; i++) {
    cost[i] = 1e12 + 7;
    if (val[i] % x == 0) {
      cost[i] = 0;
    } else if ((val[i] + 1) % x == 0 || (val[i] - 1) % x == 0) {
      cost[i] = b;
    }
  }
  for (i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + cost[i];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a;
    dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i];
  }
  return min(min(dp[n][2], dp[n][1]), dp[n][0]);
}
void pri(long long x) {
  int i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) gcd.push_back(i);
    while (x % i == 0) x = x / i;
  }
  if (x != 1) gcd.push_back(x);
}
void solve() {
  int i;
  scanf("%I64d%I64d%I64d", &n, &a, &b);
  for (i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
  }
  pri(val[1]);
  pri(val[1] + 1);
  pri(val[1] - 1);
  pri(val[n]);
  pri(val[n] + 1);
  pri(val[n] - 1);
  sort(gcd.begin(), gcd.end());
  gcd.erase(unique(gcd.begin(), gcd.end()), gcd.end());
  long long ans = 0x3fffffffffffffff, sz = gcd.size();
  for (i = 0; i < sz; i++) {
    ans = min(ans, cal(gcd[i]));
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
