#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long max(long long a, long long b) {
  long long ans = a > b ? a : b;
  return ans;
}
long long min(long long a, long long b) {
  long long ans = a < b ? a : b;
  return ans;
}
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "******************\nTime taken : "
       << (double)(time_p) / CLOCKS_PER_SEC << "\n";
}
signed main() {
  {
    string s;
    cin >> s;
    long long c0 = 0, c1 = 0, c2 = 0, c = 0;
    for (long long i = 0; i < s.size(); i++) {
      long long x = s[i] - '0';
      if (x % 3 == 1)
        c1++;
      else if (x % 3 == 2)
        c2++;
      else
        c0++;
      if (c0) {
        c++;
        c1 = 0, c2 = 0, c0 = 0;
      } else if (c1 == 3 || c2 == 3 || (c2 && c1)) {
        c++;
        c1 = 0, c2 = 0, c0 = 0;
      }
    }
    cout << c;
  }
  rtime();
  return 0;
}
