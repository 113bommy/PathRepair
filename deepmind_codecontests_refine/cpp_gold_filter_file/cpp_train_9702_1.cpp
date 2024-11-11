#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, x1, y1, x2, y2, ab1, ab2, bb1, bb2;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &x1, &y1, &x2, &y2);
  ab1 = x1 + y1, ab2 = x2 + y2, bb1 = y1 - x1, bb2 = y2 - x2;
  long long int tmp1 = (ab1) * (ab2) < 0 ? 1 : 0,
                tmp2 = (bb1) * (bb2) < 0 ? 1 : 0;
  printf("%I64d\n", max(abs(ab1 / (2 * a) - ab2 / (2 * a)) + tmp1,
                        abs(bb1 / (2 * b) - bb2 / (2 * b)) + tmp2));
}
