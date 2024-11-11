#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  int a, b;
  scanf("%lld %lld %d %d", &n, &m, &a, &b);
  if (n % m == 0) {
    puts("0");
    return 0;
  }
  long long x = n % m;
  long long res = min(x * b, (m - x) * a);
  printf("%lld\n", res);
  return 0;
}
