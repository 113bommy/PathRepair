#include <bits/stdc++.h>
using namespace std;
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}
long long GCD(long long n, long long m) {
  if (n == 0) return m;
  return GCD(m % n, n);
}
int main() {
  int n, m, k, f(0), up(0), t(0);
  cin >> n >> m >> k;
  f = (n * m * k) / 100;
  up = f / m;
  t = f - (up * m);
  if (t != 0) {
    for (int i = 0; i < up; i++) {
      cout << m << " ";
    }
    cout << t << " ";
    for (int i = 0; i < up - 1; i++) {
      cout << "0 ";
    }
  } else {
    for (int i = 0; i < up; i++) {
      cout << m << " ";
    }
    for (int i = 0; i < n - up; i++) {
      cout << "0 ";
    }
  }
  return 0;
}
