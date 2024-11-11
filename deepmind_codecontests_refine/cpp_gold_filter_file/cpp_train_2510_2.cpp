#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b;
  scanf("%lld", &b);
  int ret = 1;
  for (int d : {2, 3, 5}) {
    int c = 1;
    while (b % d == 0) ++c, b /= d;
    ret *= c;
  }
  for (long long d = 7; d * d <= b; d += 2) {
    int c = 1;
    while (b % d == 0) b /= d, ++c;
    ret *= c;
  }
  if (b > 1) ret *= 2;
  printf("%d\n", ret);
}
