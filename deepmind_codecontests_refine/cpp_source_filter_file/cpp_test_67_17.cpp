#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool op = false;
  char c = getchar();
  while (!isdigit(c)) op |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const long long N = 1e3 + 10;
long long n, al;
double pr;
signed main() {
  n = read();
  scanf("%lf", &pr);
  al = n * (n - 1) * (n - 2) / 6;
  for (long long i = 0; i <= n; i++) {
    double p1 = 1.0 * i / al * ((n - i) * (n - i - 1) / 2);
    double p2 = 1.0 * (i * (i - 1) / 2) / al * (n - i);
    double p3 = 1.0 * i * (i - 1) * (i - 2) / 6 / al;
    double res = p1 * 2 / 3 + p2 + p3;
    if (res >= pr) {
      printf("%lld", i);
      return 0;
    }
  }
  return 0;
}
