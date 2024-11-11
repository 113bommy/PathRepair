#include <bits/stdc++.h>
long long int __xor(long long int a, long long int b) { return a ^ b; }
long long int __and(long long int a, long long int b) { return a & b; }
long long int __or(long long int a, long long int b) { return a | b; }
using namespace std;
int main() {
  long long int b, c = 0, x, y, z, t, i, j, k, l1, l2, m, n, c1 = 0, c2 = 0, q,
                   a;
  scanf("%lld", &n);
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &c1);
  if (n == 1)
    cout << 0;
  else {
    if (b > a) {
      c += a;
      c2 = 2;
      if (c1 > a && n > c2)
        c += a * (n - c2);
      else if (n > c2)
        c += c1 * (n - c2);
    } else {
      c += b;
      c2 = 2;
      if (c1 > b && n > c2)
        c += b * (n - c2);
      else if (n > c)
        c += c1 * (n - c2);
    }
    cout << c;
  }
  return 0;
}
