#include <bits/stdc++.h>
int main() {
  long long n, k, m;
  scanf("%lld %lld", &n, &k);
  if (k > n)
    printf("0 0 %lld\n", n);
  else {
    m = n / 2;
    long long a, b, c;
    a = m / (k + 1);
    b = k * a;
    c = a + b;
    printf("%lld %lld %lld\n", a, b, c);
  }
}
