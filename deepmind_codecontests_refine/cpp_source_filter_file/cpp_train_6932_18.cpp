#include <bits/stdc++.h>
using namespace std;
void ext(long long int a, long long int b, long long int &d, long long int &x,
         long long int &y) {
  if (b) {
    ext(b, a % b, d, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
    d = a;
  }
}
int main() {
  int i, j, k;
  long long int A, B, C, x, y, d;
  scanf("%I64d%I64d%I64d", &A, &B, &C);
  ext(A, B, d, x, y);
  if ((-C) % d == 0) {
    printf("%I64d %I64d", (-C) / d * x, (-C) / d * y);
  } else {
    printf("%I64d", -1);
  }
  return 0;
}
