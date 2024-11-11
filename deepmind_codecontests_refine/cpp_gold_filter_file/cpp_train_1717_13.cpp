#include <bits/stdc++.h>
using namespace std;
inline long long int fast_input(void) {
  char t;
  long long int x = 0;
  long long int neg = 0;
  t = getchar();
  while ((t < 48 || t > 57) && t != '-') t = getchar();
  if (t == '-') {
    neg = 1;
    t = getchar();
  }
  while (t >= 48 && t <= 57) {
    x = (x << 3) + (x << 1) + t - 48;
    t = getchar();
  }
  if (neg) x = -x;
  return x;
}
inline void fast_output(long long int x) {
  char a[20];
  long long int i = 0, j;
  a[0] = '0';
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x == 0) putchar('0');
  while (x) {
    a[i++] = x % 10 + 48;
    x /= 10;
  }
  for (j = i - 1; j >= 0; j--) {
    putchar(a[j]);
  }
  putchar('\n');
}
void fib(long long int n, long long int& x, long long int& y,
         long long int mod) {
  if (n == 1) {
    x = y = 1;
    return;
  }
  if (n & 1) {
    fib(n - 1, y, x, mod);
    y = (y + x) % mod;
  } else {
    long long int a, b;
    fib(n >> 1, a, b, mod);
    y = (a * a + b * b) % mod;
    x = (a * b + a * (b - a + mod)) % mod;
  }
}
long long int power(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  while (b) {
    if (b % 2) ans *= a;
    a *= a;
    b /= 2;
    if (a >= mod) a %= mod;
    if (ans >= mod) ans %= mod;
  }
  return ans;
}
int main() {
  long long int n, k, l, m, i, j = 1, ans, num, a, b, x, y, arr[64];
  n = fast_input();
  k = fast_input();
  l = fast_input();
  m = fast_input();
  if (k == 0 && l == 0) {
    fast_output(1 % m);
    return 0;
  }
  fib(n + 2, a, y, m);
  b = power(2, n, m);
  if (a >= b)
    x = (b - a + m) % m;
  else
    x = b - a;
  for (i = 0; i < l; i++) {
    j *= 2;
    if (j > k) break;
  }
  if (k >= j) {
    fast_output(0);
    return 0;
  }
  num = k;
  i = 0;
  while (i < l) {
    arr[i] = num % 2;
    num /= 2;
    i++;
  }
  ans = 1;
  for (i = 0; i < l; i++) {
    if (arr[i])
      ans *= x;
    else
      ans *= a;
    if (ans >= m) ans %= m;
  }
  fast_output(ans);
  return 0;
}
