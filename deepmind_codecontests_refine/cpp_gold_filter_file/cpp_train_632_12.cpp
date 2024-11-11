#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p, x;
  scanf("%I64d%I64d%I64d", &n, &k, &p);
  if (n % 2 && k) {
    n--;
    k--;
  }
  if (n < 2 * k) {
    long long t = 2 * k - n;
    n -= t;
    k -= t;
  }
  while (p--) {
    scanf("%I64d", &x);
    if (x > n || x % 2 == 0 && (n - x) / 2 < k)
      putchar('X');
    else
      putchar('.');
  }
}
