#include <bits/stdc++.h>
using namespace std;
int b, m, x, y;
long long Rez;
long long calc(long long x, long long y) {
  long long A = (long long)(x * (x + 1)) / 2;
  A = (A * (y + 1));
  long long B = (long long)(y * (y + 1)) / 2;
  B = B * (x + 1);
  return (A + B);
}
int main() {
  scanf("%d %d", &m, &b);
  for (long long i = 0; i <= b; i++) {
    long long x = m * (b - i);
    if (calc(x, i) > Rez) {
      Rez = calc(x, i);
    }
  }
  printf("%I64d", Rez);
  return 0;
}
