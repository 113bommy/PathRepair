#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
template <class T>
T sqr(T x) {
  return x * x;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main(int argc, char** argv) {
  long long n;
  cin >> n;
  long long m = 0;
  while ((1LL << m) < n) ++m;
  long long a = n * m;
  long long b = (1LL << m);
  long long p = 1;
  --n;
  for (int i = 2; i <= m; ++i) {
    if ((n & (1LL << (m - i))) == 0) {
      b -= (1LL << (m - i));
      a += i * (1LL << (m - i));
    }
  }
  long long f = gcd(a, b);
  a /= f;
  b /= f;
  cout << a << "/" << b << endl;
}
