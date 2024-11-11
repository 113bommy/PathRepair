#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000 + 7;
const double esp = 1e-13;
long long nhan(long long x, long long y, long long m) {
  long long ans = 0;
  while (y) {
    if (y % 2) ans = (ans + x) % m;
    x = x * 2 % m;
    y /= 2;
  }
  return ans;
}
long long power(long long a, long long n, long long m) {
  unsigned long long ans = 1;
  while (n) {
    if (n % 2) ans = ans * a % m;
    a = a * a % m;
    n /= 2;
  }
  return ans;
}
bool check(long long n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  long long p[3] = {3, 5, 7};
  long long a, d;
  int r, s;
  d = n - 1;
  s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (long long i = 0; i <= 2; i++) {
    if (n == p[i]) return true;
    if (n % p[i] == 0) return false;
    a = power(p[i], d, n);
    if (a != 1) {
      for (r = 0; r < s && a != n - 1; r++) a = a * a % n;
      if (r == s) return false;
    }
  }
  return true;
}
long long phi(long long n) {
  long long ans = n;
  long long n2 = (long long)sqrt(n);
  for (long long i = 2; i <= n2; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
int s, a, b, c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  srand(time(0));
  cin >> s >> a >> b >> c;
  if (a + b + c == 0)
    cout << "0.0 0.0 0.0";
  else {
    cout << setprecision(9) << (double)s / (a + b + c) * a << " ";
    cout << setprecision(9) << (double)s / (a + b + c) * b << " ";
    cout << setprecision(9) << (double)s / (a + b + c) * c << " ";
  }
}
