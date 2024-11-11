#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:810886422")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000017;
const double EPS = 1e-9;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long nextLong(long long l, long long r) {
  uniform_int_distribution<long long> foo(l, r);
  return foo(rnd);
}
double nextDouble(double l, double r) {
  uniform_real_distribution<double> foo(l, r);
  return foo(rnd);
}
double workTime() { return double(clock()) / CLOCKS_PER_SEC; }
void myReturn(int code = 0) { exit(code); }
int gcd(int a, int b) {
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0 && gcd(i, n / i) == 1) {
      int b1 = i, b2 = n / i;
      for (int a1 = 1; a1 < b1; ++a1) {
        if ((n - 1 - a1 * b1) % b2 == 0) {
          cout << "YES" << endl << 2 << endl;
          cout << a1 << " " << b1 << endl;
          cout << (n - 1 - a1 * b1) / b2 << " " << b2 << endl;
          myReturn();
        }
      }
    }
  }
  cout << "NO" << endl;
  myReturn();
}
