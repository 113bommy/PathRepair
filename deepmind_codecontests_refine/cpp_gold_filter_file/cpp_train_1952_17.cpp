#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e6 + 5;
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int mx = 1e16;
bool comp(const int a, const int b) { return a > b; }
const double PI = 2 * acos(0.0);
long long int fac[N];
void pre() {
  fac[0] = 1LL;
  for (long long int i = 1; i < N; i++) {
    fac[i] = 1LL * i * fac[i - 1];
    if (fac[i] >= mod) fac[i] %= mod;
  }
}
long long int power(long long int a, long long int b) {
  long long int x = 1;
  while (b) {
    if (b & 1) {
      x *= a;
      if (x >= mod) x %= mod;
    }
    a *= a;
    if (a >= mod) a %= mod;
    b >>= 1;
  }
  return x;
}
long long int inv(long long int k) { return power(k, mod - 2); }
int main() {
  long double x, y, p, q;
  cin >> x >> y;
  p = (long double)(y) * (long double)(log2(x));
  q = (long double)(x) * (long double)(log2(y));
  if (abs(p - q) < 0.0000000001) {
    cout << "=";
  } else if (p < q) {
    cout << "<";
  } else {
    cout << ">";
  }
}
