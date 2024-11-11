#include <bits/stdc++.h>
using namespace std;
long long p = 1e9 + 7;
long long fi(long long n) {
  long long m = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      m -= m / i;
    }
  }
  if (n > 1) m -= m / n;
  return m;
}
pair<long long, long long> fiban(long long n, long long p) {
  if (n == 0) return {0, 1};
  pair<long long, long long> c = fiban(n / 2, p);
  long long x = c.first;
  long long y = c.second;
  long long X = (x * ((2 * y - x + p) % p) % p);
  long long Y = (x * x + y * y) % p;
  if (n % 2) {
    Y = (Y + X) % p;
    X = (Y - X + p) % p;
  }
  return {X, Y};
}
long long fib(long long n, long long mod) { return fiban(n, mod).first; }
vector<pair<long long, long long>> factrize(long long n) {
  vector<pair<long long, long long>> v;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long r = 0;
      while (n % i == 0) {
        n /= i;
        r++;
      }
      v.push_back({i, r});
    }
  }
  if (n > 1) v.push_back({n, 1});
  return v;
}
long long f(long long n) {
  return n < 10 ? n : (n / 10) * 10 + f(n % 10 + n / 10);
}
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a < b ? a : b; }
int d[456789];
int dp[456789];
int solve() {
  int n, s = 0, k = 1;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k + k + 10; i++) {
    d[i] = 0;
    dp[i] = 0;
  }
  for (int i = 0; i + i < n; i++) {
    int mi = min(a[i], a[n - i - 1]);
    int mx = max(a[i], a[n - i - 1]);
    d[2] += 2;
    d[mi + 1]--;
    d[mi + mx]--;
    d[mi + mx + 1]++;
    d[k + mx + 1]++;
  }
  s = n;
  dp[2] = d[2];
  s = d[2];
  for (int i = 3; i <= 2 * k; i++) {
    dp[i] = dp[i - 1] + d[i];
    s = min(s, dp[i]);
  }
  cout << s << endl;
  return 0;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
