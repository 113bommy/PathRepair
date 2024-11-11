#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int maxn = (int)1e5 + 10;
;
long long t, p, fib[maxn], s[maxn], dp[maxn], dp2[maxn];
long long solve(long long now) {
  long long t = 0;
  for (int i = p; i >= 1; i--) {
    if (fib[i] <= now) {
      now -= fib[i];
      s[t++] = i - 1;
    }
  }
  s[t] = -1;
  dp[t] = 1;
  dp2[t] = 0;
  for (int i = t - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] + dp2[i + 1];
    dp2[i] = (dp[i + 1] * ((s[i] - s[i + 1] - 1) / 2) +
              dp2[i + 1] * ((s[i] - s[i + 1]) / 2));
  }
  return dp[0] + dp2[0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fib[0] = 1;
  fib[1] = 1;
  p = 1;
  while (fib[p] < 1e18) {
    p++;
    fib[p] = fib[p - 1] + fib[p - 2];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long now;
    cin >> now;
    cout << solve(now) << endl;
  }
}
