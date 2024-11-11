#include <bits/stdc++.h>
using namespace std;
unsigned long long tcc, n, m;
int main() {
  scanf("%lld", &tcc);
  while (tcc--) {
    scanf("%lld %lld", &n, &m);
    unsigned long long sum = 0, m2 = m, t = 10;
    while (t-- && m2 <= n) {
      sum += m2 % 10;
      m2 += m;
    }
    m2 = m * 10;
    t = n / m2;
    sum *= t;
    n -= m2 * t;
    m2 = m;
    while (m2 < n) {
      sum += m2 % 10;
      m2 += m;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
