#include <bits/stdc++.h>
using namespace std;
long long n, i;
int f(long long x, long long y) {
  if (y == 0) return 1;
  long long t;
  t = f(x, y / 2);
  t *= t, t %= n;
  if (y % 2 == 1) t *= x, t %= n;
  return t;
}
int main() {
  cin >> n;
  if (n == 4) {
    cout << "YES" << '\n' << 1 << '\n' << 3 << '\n' << 2 << '\n' << 4;
    return 0;
  }
  if (n == 1) {
    cout << "YES" << '\n' << 1;
    return 0;
  }
  if (n == 3) {
    cout << "YES" << '\n' << 1 << '\n' << 2 << '\n' << 3;
    return 0;
  }
  if (n == 2) {
    cout << "YES" << '\n' << 1 << '\n' << 2;
    return 0;
  }
  for (i = 2; i <= sqrt(n); i++)
    if (n % i == 0) {
      cout << "NO";
      return 0;
    }
  cout << "YES" << '\n' << 1 << '\n';
  for (i = 2; i <= n - 1; i++) cout << (f(i - 1, n - 2) * i) % n << '\n';
  cout << n << '\n';
}
