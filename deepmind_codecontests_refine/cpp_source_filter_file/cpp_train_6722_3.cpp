#include <bits/stdc++.h>
using namespace std;
int fibo(int n) {
  const int MAXN = 1000;
  static unsigned int c[MAXN];
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (c[n] > 0) return c[n];
  return c[n] = fibo(n - 1) + fibo(n - 2);
}
double power(int x, int n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return power(x, n - 1) * x;
  long double y = power(x, n / 2);
  return y * y;
}
double factorial_rec(int n) {
  static long double x = 1;
  if (n == 1) return x;
  x *= n--;
  return factorial_rec(n);
}
double factorial_for(long double n) {
  for (int i = n - 1; i != 0; i--) n *= i;
  return n;
}
int main() {
  int n, sqr;
  cin >> n;
  sqr = sqrt(n);
  for (int i = sqr; i > 1; i--) {
    if (n % i == 0) {
      cout << i << " " << n / i;
      break;
    }
  }
}
