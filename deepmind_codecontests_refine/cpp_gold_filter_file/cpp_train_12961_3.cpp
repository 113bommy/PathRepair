#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
void writeln(long long n, long long m) {
  if (n == 1) {
    printf("%lldB", m - 1);
    return;
  }
  if (m == 1) {
    printf("%lldA", n - 1);
    return;
  }
  if (n > m) {
    printf("%lldA", n / m);
    writeln(n % m, m);
  } else {
    printf("%lldB", m / n);
    writeln(n, m % n);
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  if (gcd(n, m) == 1)
    writeln(n, m);
  else
    puts("Impossible");
  return 0;
}
