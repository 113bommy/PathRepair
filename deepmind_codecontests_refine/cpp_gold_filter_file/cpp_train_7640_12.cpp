#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;
const int maxn = (int)2e5 + 10;
int F[maxn];
void add(int &x, int y) {
  x += y;
  x -= (x >= mod) * mod;
}
int binpow(int n, int m) {
  int res = 1;
  while (m) {
    if (m & 1) res = res * 1LL * n % mod;
    n = n * 1LL * n % mod;
    m >>= 1;
  }
  return res;
}
int f(int n) { return F[n]; }
int c(int n, int m) {
  return f(n) * 1LL * binpow(f(m), mod - 2) % mod * 1LL *
         binpow(f(n - m), mod - 2) % mod;
}
int calc(int n, int m, int g) {
  if (m == 0) return 1 - n % 2 == g;
  if (n == 0) return g == (m == 1);
  int res = 0;
  if (g == 0) add(res, c(n + m - 1, m - 1));
  for (int i = 1; i <= n; i++)
    if (((i % 2) ^ (m == 1 && i == n)) == g) {
      add(res, c(n - i + m - 1, m - 1));
    }
  return res;
}
int main() {
  F[0] = 1;
  for (int i = 1; i < maxn; i++) {
    F[i] = F[i - 1] * 1LL * i % mod;
  }
  int n, m, g;
  cin >> n >> m >> g;
  cout << calc(n, m, g) << endl;
  return 0;
}
