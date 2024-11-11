#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline string tostr(const T& x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
const double EPS = 1e-6;
const int INF = 1000 * 1000 * 1000;
const char CINF = 102;
const long long LINF = INF * 1ll * INF;
const double PI = 3.1415926535897932384626433832795;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
unsigned int gcd(unsigned int a, unsigned int b) {
  return a ? gcd(b % a, a) : b;
}
const long long mod = INF + 7;
long long dp[510][510];
int main() {
  int A = 0, B = 0;
  {
    int n;
    cin >> n;
    for (int i = 0; i < (n); ++i) {
      int a;
      cin >> a;
      if (a == 1)
        ++A;
      else
        ++B;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= B; ++i) {
    dp[0][i] = dp[0][i - 1] * i % mod;
  }
  for (int a = 1; a <= A; ++a) {
    for (int b = 0; b < (B + 1); ++b) {
      long long r = 0;
      long long t = 1;
      for (int k = 0; k <= b; ++k) {
        r = (r + dp[a - 1][b - k] * t) % mod;
        if (a >= 2) {
          r = (r + dp[a - 2][b - k] * t % mod * (a - 1) * (k + 1)) % mod;
        }
        t = t * (b - k) % mod;
      }
      dp[a][b] = r;
    }
  }
  cout << dp[A][B];
  return 0;
}
