#include <bits/stdc++.h>
using namespace std;
long long my_pow(long long x) { return x * x * x; }
long long steps(long long m) {
  if (m <= 7) return m;
  long long x = 1;
  while (my_pow(x + 1) <= m) ++x;
  return 1 + steps(max(m - my_pow(x), my_pow(x) - 1 - my_pow(x - 1)));
}
int main() {
  long long m;
  scanf("%lld", &m);
  long long subtracted = 0, steps_so_far = 0;
  while (m) {
    ++steps_so_far;
    long long x = 1;
    while (my_pow(x + 1) <= m) ++x;
    if (steps(m) == 1 + steps(m - my_pow(x))) {
      m -= my_pow(x);
      subtracted += my_pow(x);
    } else {
      m = my_pow(x) - 1 - my_pow(x - 1);
      subtracted += my_pow(x - 1);
    }
  }
  printf("%lld %lld\n", steps_so_far, subtracted);
  return 0;
}
