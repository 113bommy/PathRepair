#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}
const int N = 2e5 + 11;
int n, m, a[N], k;
struct uzi {
  int a, b;
  bool operator<(const uzi& t) const { return b > t.b; }
} p[N];
long long dp[2033], s[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= m; i++) cin >> p[i].a >> p[i].b;
  for (int i = 1; i <= k; i++) {
    dp[i] = dp[i - 1] + a[i];
    for (int j = 1; j <= m; j++) {
      if (p[j].a <= i) {
        int l = i - p[j].a;
        dp[i] = min(dp[i], dp[i - p[j].a] + s[i] - s[l] + s[i - p[j].a] -
                               s[i + p[j].b - p[j].a]);
      }
    }
  }
  cout << dp[k] << endl;
  return 0;
}
