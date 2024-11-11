#include <bits/stdc++.h>
using namespace std;
int T;
double pi = acos(-1.0);
long long factorial(long long x) {
  long long total = 1;
  for (int i = 2; i <= x; i++) total *= i;
  return total;
}
bool isprime(long long x) {
  vector<bool> prime(x + 1, 1);
  prime[0] = prime[1] = 0;
  for (long long i = 2; i * i <= x; i++)
    if (prime[i])
      for (long long j = i * i; j <= x; j += i) prime[j] = 0;
  return prime[x];
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long temp = 1;
long long fastpow(long long base, long long exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return (temp * base);
  if (exponent % 2 == 0)
    return fastpow(base * base, exponent / 2);
  else {
    temp *= base;
    fastpow(base * base, exponent / 2);
  }
}
long fib(long n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n - 2) + fib(n - 1);
}
void solve() {
  int n, diff;
  cin >> n >> diff;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = make_pair(x, y);
  }
  sort(v.begin(), v.end());
  long long l = 0, r = 1, sum = v[0].second, ans = sum;
  while (r < n) {
    if (abs(v[r].first - v[l].first) < diff) {
      sum += v[r].second;
      ans = max(sum, ans);
      r++;
    } else {
      sum -= v[l].second;
      l++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
