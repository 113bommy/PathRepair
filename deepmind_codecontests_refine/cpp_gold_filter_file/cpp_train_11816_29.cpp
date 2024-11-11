#include <bits/stdc++.h>
using namespace std;
long long fa[400005], iv[400005];
pair<long long, long long> p[2005];
long long dp[2005];
long long pw(long long bs, long long x) {
  long long ans = 1;
  while (x) {
    if (x & 1) ans = ans * bs % 1000000007;
    bs = bs * bs % 1000000007;
    x /= 2;
  }
  return ans % 1000000007;
}
void init() {
  fa[0] = iv[0] = 1;
  for (int i = 1; i <= 400000; i++) {
    fa[i] = fa[i - 1] * i % 1000000007;
    iv[i] = pw(fa[i], 1000000007 - 2) % 1000000007;
  }
}
long long cal(long long n, long long m) {
  if (m > n) return 0;
  long long ans = fa[n] % 1000000007;
  ans = (ans * iv[m] % 1000000007) * iv[n - m] % 1000000007;
  return ans;
}
long long lu(long long n, long long m) {
  if (m == 0) return 1;
  return cal(n % 1000000007, m % 1000000007) *
         lu(n / 1000000007, m / 1000000007) % 1000000007;
}
int main() {
  init();
  long long n, m, k;
  cin >> n >> m >> k;
  n--;
  m--;
  for (int i = 0; i < k; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first--;
    p[i].second--;
  }
  sort(p, p + k);
  p[k].first = n;
  p[k].second = m;
  for (int i = 0; i <= k; i++) {
    long long sum = 0;
    for (int j = 0; j < i; j++) {
      long long x = p[i].first - p[j].first, y = p[i].second - p[j].second;
      if (x < 0 || y < 0) continue;
      sum = (sum + lu(x + y, x) * dp[j] % 1000000007) % 1000000007;
    }
    dp[i] = (cal(p[i].first + p[i].second, p[i].first) - sum + 1000000007) %
            1000000007;
  }
  cout << dp[k] % 1000000007 << endl;
}
