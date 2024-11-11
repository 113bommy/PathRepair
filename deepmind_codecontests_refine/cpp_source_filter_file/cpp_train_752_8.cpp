#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c = 1, o = 0;
  scanf("%I64d%I64d", &a, &b);
  while (a || b) {
    o += (a % 3 + b % 3) % 3 * c;
    a /= 3;
    b /= 3;
    c *= 3;
  }
  printf("%I64d\n", o);
}
