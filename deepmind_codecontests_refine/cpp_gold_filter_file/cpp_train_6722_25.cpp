#include <bits/stdc++.h>
using namespace std;
const long long MX = 4e5 + 9;
const long double pi = acos(-1);
const long long mod = 1e9 + 7;
long long po(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long x = po(a, b / 2);
  x *= x % mod;
  if (b % 2) {
    x *= a % mod;
  }
  return x % mod;
}
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int main() {
  int n;
  cin >> n;
  int a = 1, b = n;
  for (int i = 1; i < n; i++) {
    if (n % i == 0 && i <= n / i) {
      if (abs(i - n / i) < abs(a - b)) {
        a = i;
        b = n / i;
      }
    }
  }
  cout << a << " " << b;
  return 0;
}
