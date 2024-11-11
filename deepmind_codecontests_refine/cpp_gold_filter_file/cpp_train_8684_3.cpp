#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const double EPS = 10e-9;
bool primetest(int n) {
  for (int i = 2; i * i <= n; ++i)
    if ((n % i) == 0) return false;
  return true;
}
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (!(a * b)) return a + b;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n, t, v, u;
  long long numerator, denominator, nwd;
  cin >> t;
  for (int i = 0; i < (t); ++i) {
    cin >> n;
    if (n == 2) {
      cout << "1/6" << endl;
      continue;
    }
    if (n == 3) {
      cout << "7/30" << endl;
      continue;
    }
    for (int j = n; j >= (n - 310); --j)
      if (primetest(j)) {
        v = j;
        break;
      }
    for (int j = n + 1; j <= (n + 310); ++j)
      if (primetest(j)) {
        u = j;
        break;
      }
    numerator = u * v - 2 * u + 2 * (n - v + 1);
    denominator = 2 * u * v;
    nwd = gcd(numerator, denominator);
    cout << (numerator / nwd) << "/" << (denominator / nwd) << endl;
  }
  return 0;
}
