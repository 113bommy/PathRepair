#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int inf = 1e9;
double eps = 1e-2;
ifstream in("input.txt");
ofstream out("output.txt");
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1 = 0, y1 = 0;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 2; i * i < n; i++) {
    if (n % i == 0) {
      long long x, y;
      long long g = gcd(i, n / i, x, y);
      if (g == 1) {
        x *= n - 1;
        y *= n - 1;
        if (x < 0) {
          long long q = (x / (n / i) - 1);
          x -= q * n / i;
          y += q * i;
        }
        if (y < 0) {
          long long q = (y / i - 1);
          x += q * n / i;
          y -= q * i;
        }
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << x << " " << n / i << endl;
        cout << y << " " << i << endl;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
