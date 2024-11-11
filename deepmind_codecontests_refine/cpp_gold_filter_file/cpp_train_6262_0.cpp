#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
lint _pow(lint a, lint n) {
  if (n == 0)
    return 1;
  else {
    lint res = 1;
    lint buf = a;
    while (n > 0) {
      if (n % 2 == 1) {
        res *= buf;
        res %= 998244353LL;
      }
      buf *= buf;
      buf %= 998244353LL;
      n /= 2;
    }
    return res;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n + 10, 0);
  for (lint i = 0; i < (int)n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  lint ans = 0;
  vector<lint> dp(n + 10, 0);
  dp[0] = 1;
  vector<lint> rev(n + 10);
  for (lint i = 0; i < (int)n + 10; i++) rev[i] = _pow(i, 998244353LL - 2);
  for (lint i = 0; i < (int)n + 10; i++) {
    if (c[i] == 0) continue;
    if (c[i] >= 2) {
      for (lint j = 0; j < (int)n + 10; j++) {
        lint p = dp[j];
        p *= c[i];
        p %= 998244353LL;
        p *= c[i] - 1;
        p %= 998244353LL;
        p *= rev[n - j];
        p %= 998244353LL;
        p *= rev[n - j - 1];
        p %= 998244353LL;
        ans += p;
        ans %= 998244353LL;
      }
    }
    vector<lint> ndp(n + 10, 0);
    for (lint j = 0; j < (int)n + 10; j++) ndp[j] += dp[j];
    for (lint j = 1; j < (int)n + 10; j++) {
      lint p = dp[j - 1];
      p *= c[i];
      p %= 998244353LL;
      p *= rev[n - j + 1];
      p %= 998244353LL;
      ndp[j] += p;
      ndp[j] %= 998244353LL;
    }
    dp = ndp;
  }
  cout << ans << endl;
  return 0;
}
