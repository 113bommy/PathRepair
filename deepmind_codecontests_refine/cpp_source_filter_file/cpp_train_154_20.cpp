#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (((a * b) / gcd(a, b))); }
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long binpow(long long a, long long n, long long c) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    res %= c;
    a *= a;
    a %= c;
    n >>= 1;
  }
  res = (res + c) % c;
  return res;
}
void nxi(int& n) {
  bool min = 0;
  char c;
  n = 0;
  while ((c = getc(stdin)) && c <= 32)
    ;
  if (c == '-')
    min = 1;
  else
    n = c - 48;
  while ((c = getc(stdin)) && c > 32) n = (n << 3) + (n << 1) + c - 48;
  if (min) n = -n;
}
void prl(int n) {
  if (n == 0) {
    puts("0");
    return;
  }
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  static int s[10];
  int top = 0;
  while (n > 0) s[top++] = n % 10, n /= 10;
  while (top--) putchar(s[top] + 48);
  puts("");
}
using namespace std;
const int nmax = 1000010;
int n, a[nmax], b[nmax];
vector<pair<long double, long double> > v;
long double x, y, z;
long double calc(int n) {
  if (n == 1) return pow(y, z) * log(x);
  if (n == 2) return pow(z, y) * log(x);
  if (n == 3) return y * z * log(x);
  if (n == 4) return z * y * log(x);
  if (n == 5) return pow(x, z) * log(y);
  if (n == 6) return pow(z, x) * log(y);
  if (n == 7) return x * z * log(y);
  if (n == 8) return z * x * log(y);
  if (n == 9) return pow(x, y) * log(z);
  if (n == 10) return pow(y, x) * log(z);
  if (n == 11) return x * y * log(z);
  if (n == 12) return y * x * log(z);
}
long double calc2(int n) {
  if (n == 1) return z * log(y) + log(log(x));
  if (n == 2) return y * log(z) + log(log(x));
  if (n == 3) return log(y) + log(z) + log(log(x));
  if (n == 4) return log(z) + log(y) + log(log(x));
  if (n == 5) return z * log(x) + log(log(y));
  if (n == 6) return x * log(z) + log(log(y));
  if (n == 7) return log(x) + log(z) + log(log(y));
  if (n == 8) return log(z) + log(x) + log(log(y));
  if (n == 9) return y * log(x) + log(log(z));
  if (n == 10) return x * log(y) + log(log(z));
  if (n == 11) return log(x) + log(y) + log(log(z));
  if (n == 12) return log(y) + log(x) + log(log(z));
}
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(0);
  cin >> x >> y >> z;
  for (int i = 1; i <= 12; i++) v.push_back(make_pair(calc2(i), -i));
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int num = -v[0].second;
  if (num == 1)
    puts("x^y^z");
  else if (num == 2)
    puts("x^z^y");
  else if (num == 3)
    puts("(x^y)^z");
  else if (num == 4)
    puts("(x^z)^y");
  else if (num == 5)
    puts("y^x^z");
  else if (num == 6)
    puts("y^z^x");
  else if (num == 7)
    puts("(y^x)^z");
  else if (num == 8)
    puts("(y^z)^x");
  else if (num == 9)
    puts("z^x^y");
  else if (num == 10)
    puts("z^y^x");
  else if (num == 11)
    puts("(z^x)^y");
  else
    puts("(z^y)^x");
  return 0;
}
