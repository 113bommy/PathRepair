#include <bits/stdc++.h>
using namespace std;
double PI = (acos(-1));
long long md = 1000000007;
long long pw(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m);
    b /= 2;
  }
  return c;
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long nc2(long long n) { return (1ll * n * (n - 1)) / 2; }
long long nc3(long long n) { return (1ll * n * (n - 1) * (n - 2)) / 6; }
bool prime(long long a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return false;
  }
  return true;
}
long long ceel(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
void Sieve(vector<int> &primes) {
  bool IsPrime[500];
  memset(IsPrime, true, sizeof(IsPrime));
  for (int p = 2; p * p < 500; p++) {
    if (IsPrime[p] == true) {
      for (int i = p * p; i < 500; i += p) IsPrime[i] = false;
    }
  }
  for (int p = 2; p < 500; p++)
    if (IsPrime[p]) primes.push_back(p);
}
void solve() {
  long long n, k, sum = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<long long>> v(k);
  vector<long long> l(k, 0);
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      v[i % k].push_back(0);
    else
      v[i % k].push_back(1), sum++, l[i % k]++;
  }
  long long ans = sum;
  for (long long i = 0; i < k; i++) {
    long long cur = sum - l[i], r = (int)v[i].size();
    long long dp[r][2];
    if (s[i] == '0')
      dp[0][0] = 0, dp[0][1] = 1;
    else
      dp[0][1] = 0, dp[0][0] = 1;
    for (long long j = 1; j < r; j++) {
      dp[j][1] = min(dp[j - 1][0], dp[j - 1][1]);
      if (s[(j * k) + i] == '0') dp[j][1]++;
      dp[j][0] = dp[j - 1][0];
      if (s[(j * k) + i] == '1') dp[j - 1][0]++;
    }
    if (r >= 2) {
      long long x = 0, y = 0;
      if (s[(r - 1) * k + i] == '0')
        y++;
      else
        x++;
      ans = min(ans, cur + (min(x, y) + min(dp[r - 2][0], dp[r - 2][1])));
      for (long long j = r - 2; j > 0; j--) {
        long long temp = min(x, y);
        y = temp;
        if (s[j * k + i] == '0')
          y++;
        else
          x++;
        ans = min(ans, cur + (min(x, y) + min(dp[j - 1][0], dp[j - 1][1])));
      }
    } else
      ans = min(ans, cur + min(dp[r - 1][0], dp[r - 1][1]));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
