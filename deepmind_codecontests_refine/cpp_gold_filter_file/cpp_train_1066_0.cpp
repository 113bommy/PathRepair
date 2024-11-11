#include <bits/stdc++.h>
using namespace std;
string toString(long long int x) {
  stringstream ss;
  ss << x;
  string s = ss.str();
  return s;
}
long long int toInteger(string s) {
  stringstream ss(s);
  long long int x = 0;
  ss >> x;
  return x;
}
long long int modularExponentiation(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modularExponentiation((x * x) % 1000000007, n / 2);
  else
    return (x * modularExponentiation((x * x) % 1000000007, (n - 1) / 2)) %
           1000000007;
}
long long int extended_GCD(long long int a, long long int b, long long int &x,
                           long long int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = extended_GCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return gcd;
}
long long int modInverse(long long int A, long long int M = 1000000007) {
  long long int x, y;
  extended_GCD(A, M, x, y);
  return (x % M + M) % M;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int kk = 0; kk < t; kk++) {
    long long int n, x, m;
    long long int k = 0, sum = 1, c1, c2;
    cin >> n >> x >> m;
    for (long long int i = 0; i < m; i++) {
      long long int a, b;
      cin >> a >> b;
      if (k == 1) {
        if (a >= c1 && a <= c2 && b >= c2) {
          c2 = b;
          sum = c2 - c1 + 1;
        } else if (c1 >= a && c1 <= b && c2 >= b) {
          c1 = a;
          sum = c2 - c1 + 1;
        } else if (a <= c1 && b >= c2) {
          c1 = a;
          c2 = b;
          sum = b - a + 1;
        }
      } else if (x >= a && x <= b) {
        k = 1;
        c1 = a;
        c2 = b;
        sum = c2 - c1 + 1;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
