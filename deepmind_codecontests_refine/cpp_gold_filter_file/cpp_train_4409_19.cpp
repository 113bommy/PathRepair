#include <bits/stdc++.h>
using namespace std;
bool gcd(long long int a, long long int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b % a, a);
}
bool isPrime(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int Euclid(long long int a, long long int b, long long int &x,
                     long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int gcd = Euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}
long long int modInverse(long long int b, long long int m) {
  long long int x, y;
  long long int g = Euclid(b, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long int modDivice(long long int a, long long int b, long long int m) {
  a %= m;
  long long int inv = modInverse(b, m);
  if (inv == -1) return -1;
  return (inv * a) % m;
}
long long int pow(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long int t = pow(a, n / 2);
  t *= t;
  if (n % 2) t = t * a;
  return t;
}
long long int powMod(long long int a, long long int n, long long int m) {
  if (n == 0) return 1 % m;
  if (n == 1) return a % m;
  long long int t = powMod(a, n / 2, m) % m;
  t = (t * t) % m;
  if (n % 2) t = (t * a) % m;
  return t % m;
}
long long int powMod2(long long int a, long long int n, long long int m) {
  long long int res = 1;
  for (long long int i = n; i; i >>= 1) {
    if (i & 1) res = (res * a) % m;
    a = (a * a) % m;
  }
  return res;
}
long long int phiEuler(long long int n) {
  long long int res = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= (res / i);
    }
  }
  if (n != 1) res -= (res / n);
  return res;
}
void BornPhi(long long int n) {
  long long int phi[n + 1];
  for (long long int i = 1; i <= n; i++) {
    phi[i] = i;
  }
  for (long long int p = 2; p <= n; p++) {
    if (phi[p] == p) {
      phi[p] = p - 1;
      for (long long int i = 2 * p; i <= n; i += p) {
        phi[i] = (phi[i] / p) * (p - 1);
      }
    }
  }
}
long double C(long long int n, long long int k) {
  long double res = 1;
  if (k > n - k) k = n - k;
  for (long long int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
bool isPara(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - 1 - i]) return false;
  }
  return true;
}
long long int n, m;
long long int f[10001], ff[10001];
char a[1001][1001];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  long long int tmp = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '*') {
        f[i]++;
        ff[j]++;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (f[i] == 1) cout << i << " ";
  }
  for (int i = 0; i <= m; i++) {
    if (ff[i] == 1) cout << i;
  }
  return 0;
}
