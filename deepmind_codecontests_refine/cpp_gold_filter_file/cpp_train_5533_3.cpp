#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long big = inf * 1LL * inf;
vector<int> fact[100010], primef[100010];
long long m;
long long dp[100010];
long long fpow(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1)
    return x;
  else if (n % 2)
    return x * fpow((x * x) % inf, (n - 1) / 2) % inf;
  else
    return fpow((x * x) % inf, n / 2);
}
int f(long long y, long long x) {
  int bMax = m / y;
  int a = x / y;
  int cnt = 0;
  for (int i = 1; i < (1 << primef[a].size()); ++i) {
    int prod = 1;
    int sign = -1;
    for (int j = 0; j < primef[a].size(); ++j) {
      if (i & (1 << j)) {
        prod *= primef[a][j];
        sign *= -1;
      }
    }
    cnt = cnt + sign * (bMax / prod);
  }
  return bMax - cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  bool prime[100010];
  memset(prime, 1, sizeof prime);
  prime[1] = 0;
  for (int i = 2; i <= m; ++i) {
    if (prime[i]) {
      for (int j = 2 * i; j <= m; j += i) {
        prime[j] = 0;
        primef[j].push_back(i);
      }
      primef[i].push_back(i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 2 * i; j <= m; j += i) fact[j].push_back(i);
  }
  long long minv = fpow(m, inf - 2);
  for (int i = 2; i <= m; ++i) {
    long long sum = 0;
    for (int factor : fact[i]) {
      sum = sum + (dp[factor] * f(factor, i) % inf);
      if (sum >= inf) sum -= inf;
    }
    sum = sum * minv % inf;
    sum++;
    long long cnt = m / i;
    dp[i] = sum * m % inf * fpow(m - cnt, inf - 2) % inf;
  }
  long long ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = ans + dp[i];
    if (ans >= inf) ans -= inf;
  }
  cout << (1 + ans * minv % inf) % inf;
  return 0;
}
