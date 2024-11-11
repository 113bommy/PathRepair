#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long big = 1000000007ll;
long long n, m, k, r;
vector<long long> P;
long long mark[100000] = {0};
bool f(long long wins, long long plays) {
  if (plays == 0) return wins <= 0;
  if (plays == 1) return (wins <= 0);
  if (plays % 2 == 0) return f(wins - 1, plays / 2);
  return (f(wins - 1, plays / 2 + 1) & f(wins - 2, plays / 2));
}
long long bs() {
  long long l = 1;
  long long r = n;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (f(mid, n)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
long long DP[1000] = {0};
long long dp(long long i) {
  if (i == 1) return 2;
  if (i == 2) return 3;
  if (DP[i] != 0) return DP[i];
  DP[i] = dp(i - 1) + dp(i - 2);
  return DP[i];
}
long long ugly(long long i) {
  long long ans = 0;
  long long i2 = i;
  if (i == 2) return 1;
  while (i2 > 1) {
    i2 += i2 % 3;
    i2 /= 3;
    ans += 2;
  }
  return ans;
}
int main() {
  long long c1, c2, c3;
  long long a, b, c, e;
  cin >> n;
  long long t = 1;
  long long ans = 1;
  for (c1 = 1; c1 <= n; c1++) {
    if (dp(c1) > n) {
      ans = c1 - 1;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
