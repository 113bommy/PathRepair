#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
const double e = 2.718281828459;
inline int sgn(double a);
inline long long gcd(long long a, long long b);
inline long long mod_pow(long long x, long long n, long long mod);
inline void Fill(int *a, int *b, int c);
inline int b_s1(int *a, int l, int r, int k);
long long a[300005];
long long b[300005];
int main() {
  b[0] = 1;
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    b[i] = mod_pow(2, i, mod);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (((-b[n - i] + b[i - 1] + mod) % mod) * (a[i] % mod)) % mod;
  }
  cout << (ans + mod) % mod << endl;
  return 0;
}
long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}
