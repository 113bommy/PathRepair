#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long int factorialmod(long long int n) {
  long long int fact = 1;
  for (long long int i = 1; i <= n; i++) fact = (fact * i) % p;
  fact = fact % p;
  return fact;
}
long long int factorial(long long int n) {
  long long int fact = 1;
  for (long long int i = 1; i <= n; i++) fact = (fact * i);
  return fact;
}
long long int powermod(long long int a, long long int b) {
  a = a % p;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
long long int power(long long int a, long long int b) {
  a = a;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int modInverse(long long int x) { return power(x, p - 2); }
long long int nCi(long long int n, long long int i, long long int fact[]) {
  if (n < i) return 0;
  if (i == 0) return 1;
  return (fact[n] % p * modInverse(fact[i]) % p * modInverse(fact[n - i]) % p) %
         p;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int exgcd(long long int a, long long int b, long long int &x,
                    long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int d = exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
bool find_any_dio_solution(long long int a, long long int b, long long int c,
                           long long int &x0, long long int &y0,
                           long long int &g) {
  g = exgcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}
void matmultiply(long long int F[2][2], long long int M[2][2]) {
  long long int x = (F[0][0] * M[0][0] % p + F[0][1] * M[1][0] % p) % p;
  long long int y = (F[0][0] * M[0][1] % p + F[0][1] * M[1][1] % p) % p;
  long long int z = (F[1][0] * M[0][0] % p + F[1][1] * M[1][0] % p) % p;
  long long int w = (F[1][0] * M[0][1] % p + F[1][1] * M[1][1] % p) % p;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void matpower(long long int F[2][2], long long int n) {
  if (n == 0 || n == 1) return;
  long long int M[2][2] = {{1, 1}, {1, 0}};
  matpower(F, n / 2);
  matmultiply(F, F);
  if (n % 2 != 0) matmultiply(F, M);
}
long long int fib(long long int n) {
  long long int F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0) return 0;
  matpower(F, n - 1);
  return F[0][0] % p;
}
long long int bin_search(long long int a[], long long int n,
                         long long int val) {
  long long int l = 0, u = n - 1, mid;
  while (l <= u) {
    mid = (l + u) / 2;
    if (val < a[mid])
      u = mid - 1;
    else if (val > a[mid])
      l = mid + 1;
    else {
      break;
    }
  }
  return (l + u) / 2;
}
void solution() {
  long long int n, t;
  cin >> n >> t;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int x = 0, s = 0, maxi = 0;
  long long int pre[n];
  pre[0] = s = a[0];
  if (s > t) {
    x = 1;
    s = 0;
  } else {
    if (n == 1) maxi = 1;
  }
  for (long long int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + a[i];
    s = s + a[i];
    if (s > t) {
      maxi = max(maxi, i - x);
      s = s - a[x++];
    } else {
      if (i == n - 1) {
        maxi = max(maxi, i + 1 - x);
      }
    }
  }
  cout << maxi;
}
int32_t main() {
  solution();
  return 0;
}
