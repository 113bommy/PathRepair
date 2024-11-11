#include <bits/stdc++.h>
using namespace std;
long long choose(long long n, long long k);
bool isprime(long long n);
long long power(long long x, long long y, long long p);
int maxi(int Count, ...);
int mini(int Count, ...);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long x[n], y[n], cnt = 0;
  long long dp[100005] = {};
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    cnt = 0;
    long long w = x[i];
    for (int j = 1; j * j <= w; j++) {
      if (w % j == 0) {
        if (dp[j] <= i - y[i]) cnt++;
        if (w != j * j && dp[w / j] <= i - y[i]) cnt++;
        dp[j] = i + 1;
        dp[w / j] = i + 1;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
long long choose(long long n, long long k) {
  if (k == 0) return 1;
  return (n * choose(n - 1, k - 1)) / k;
}
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int maxi(int Count, ...) {
  va_list Numbers;
  va_start(Numbers, Count);
  int ma = INT_MIN;
  for (int i = 0; i < Count; i++) ma = max(ma, va_arg(Numbers, int));
  va_end(Numbers);
  return ma;
}
int mini(int Count, ...) {
  va_list Numbers;
  va_start(Numbers, Count);
  int mi = INT_MAX;
  for (int i = 0; i < Count; i++) mi = min(mi, va_arg(Numbers, int));
  va_end(Numbers);
  return mi;
}
