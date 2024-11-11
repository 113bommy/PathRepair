#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;
  for (long long i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long p_factors(long long &n, long long p) {
  long long res = 0;
  while (n % p == 0) {
    res++;
    n = n / p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string division(long long a, long long b) {
  if (a == 0) return "null";
  if (b == 0) return "0";
  string s;
  if (a * b < 0)
    s = "-";
  else
    s = "";
  a = abs(a);
  b = abs(b);
  long long c = gcd(a, b);
  a = a / c;
  b = b / c;
  s += to_string(b);
  s += "/";
  s += to_string(a);
  return s;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long h, w;
  cin >> h >> w;
  long long ans = 0;
  for (long long i = 1; i < h; i++) {
    for (long long j = 1; j < w; j++) {
      ans += max(i, h - i) * max(j, w - j);
    }
  }
  cout << ans;
  return 0;
}
