#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
const int N = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e3;
long long mod = 100;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long quick_pow(long long x, long long n) {
  long long num = x, ansult = 1;
  ansult %= mod;
  while (n) {
    if (n & 1) {
      ansult = ansult * num % mod;
      n--;
    }
    num = num * num % mod;
    n >>= 1;
  }
  return ansult;
}
long long extra_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long exgcd = extra_gcd(b, a % b, y, x);
  y -= a / b * x;
  return exgcd;
}
long long read() {
  long long c = getchar(), Nig = 1, x = 0;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') Nig = -1, c = getchar();
  while (isdigit(c)) x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
  return Nig * x;
}
deque<long long> q;
long long c[N];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      c[i] = read();
      q.push_back(c[i]);
    }
    long long temp = 0;
    long long a = 0, b = 0;
    long long sum = 0;
    long long ans = 0;
    while (!q.empty()) {
      while (sum <= t && !q.empty()) {
        sum += q.front();
        q.pop_front();
      }
      a += sum;
      temp = sum;
      sum = 0;
      ans++;
      if (q.empty()) {
        break;
      }
      while (sum <= t && !q.empty()) {
        sum += q.back();
        q.pop_back();
      }
      b += sum;
      temp = sum;
      sum = 0;
      ans++;
    }
    cout << ans << " " << a << " " << b << endl;
  }
  return 0;
}
