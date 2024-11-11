#include <bits/stdc++.h>
using namespace std;
double Fib(double x, double z);
string BinDec(unsigned long long x);
string StringInt(long long x);
unsigned long long StringInt(string x);
unsigned long long BinDec(string x);
unsigned long long POWMOD(unsigned long long x, unsigned long long y,
                          unsigned long long mod);
long long POWE(long long, long long);
int x, arr[1000000] = {}, a[20000] = {};
int ans = 0, y;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j, z, c = 0;
  cin >> x >> y;
  for (i = 0; i < x; i++) {
    cin >> z;
    arr[i] = z % y;
    if (arr[i] == 0) c = 1;
  }
  if (c) {
    cout << "YES";
    return 0;
  }
  a[0] = 1;
  for (i = x - 1; i >= 0; i--) {
    for (j = 1000; j >= 0; j--) {
      if (a[j] == 1 && (j + arr[i]) % y == 0) {
        cout << "YES";
        return 0;
      }
      if (a[j] == 1) {
        a[(j + arr[i])] = a[j];
      }
    }
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
double Fib(double x, double z) {
  int i = 0;
  double f = x, r = x, t;
  for (i = 2; i < z; i++) {
    t = f;
    f += r;
    r = t;
  }
  return f;
}
string BinDec(unsigned long long x) {
  string z;
  while (1) {
    z += ((x % 3) + '0');
    x /= 3;
    if (x == 0) break;
  }
  while (1) {
    if (z.size() == 30) break;
    z += '0';
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long BinDec(string x) {
  long long i;
  unsigned long long z = 1, a = 0;
  for (i = x.size() - 1; i >= 0; i--) {
    if (x[i] == '1') a += z;
    if (x[i] == '2') a += (2 * z);
    z *= 3;
  }
  return a;
}
unsigned long long StringInt(string x) {
  unsigned long long z = 0, i;
  for (i = 0; i < x.size(); i++) {
    z *= 10;
    z += (x[i] - '0');
  }
  return z;
}
string StringInt(long long x) {
  string z;
  while (x != 0) {
    z += (x % 10 + '0');
    x /= 10;
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long POWMOD(unsigned long long base, unsigned long long exp,
                          unsigned long long mod) {
  unsigned long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    res %= mod;
    exp /= 2;
    base = (base * base);
    base %= mod;
  }
  return res % mod;
}
long long POWE(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    exp /= 2;
    base = (base * base);
  }
  return res;
}
