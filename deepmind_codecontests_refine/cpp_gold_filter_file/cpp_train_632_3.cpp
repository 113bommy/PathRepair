#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p, a;
  cin >> n >> k >> p;
  if (n % 2 && k) {
    n--;
    k--;
  }
  if (2 * k > n) {
    long long t = 2 * k - n;
    n -= t;
    k -= t;
  }
  while (p--) {
    cin >> a;
    if ((a > n) || ((a % 2 == 0) && ((n - a) / 2 < k)))
      putchar('X');
    else
      putchar('.');
  }
}
