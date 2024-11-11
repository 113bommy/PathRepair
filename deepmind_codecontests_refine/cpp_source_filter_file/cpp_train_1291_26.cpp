#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, h;
  while (scanf("%lld%lld", &r, &h) != EOF) {
    long long t, sum = 1, a, b;
    a = h % r;
    b = h / r;
    if (a >= r / 2.0) sum = 2;
    if (a >= r / 2.0 * sqrt(2.0)) sum = 3;
    sum = sum + 2 * b;
    printf("%lld\n", sum);
  }
  return 0;
}
