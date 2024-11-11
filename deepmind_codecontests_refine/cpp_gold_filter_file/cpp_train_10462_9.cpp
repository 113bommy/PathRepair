#include <bits/stdc++.h>
using namespace std;
struct greater {
  template <class T>
  bool operator()(T const &a, T const &b) const {
    return a > b;
  }
};
unsigned long long subV(unsigned long long a, unsigned long long b,
                        unsigned long long c, unsigned long long l) {
  if (a < b + c) {
    return 0;
  }
  unsigned long long sum = (l + 2) * (l + 1) / 2;
  unsigned long long df = a - b - c;
  if (df >= 0) {
    unsigned long long sub = (df + 2) * (df + 1) / 2;
    return min(sub, sum);
  }
  return 0;
}
int main() {
  int a, b, c, l;
  scanf("%d %d %d %d", &a, &b, &c, &l);
  unsigned long long total = 0;
  for (unsigned long long i = 0; i <= l; i++) {
    total += (i + 2) * (i + 1) / 2;
  }
  for (unsigned long long i = 0; i <= l; i++) {
    total -= subV(a + i, b, c, l - i);
    total -= subV(b + i, a, c, l - i);
    total -= subV(c + i, a, b, l - i);
  }
  printf("%I64d", total);
  return 0;
}
