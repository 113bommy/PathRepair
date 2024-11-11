#include <bits/stdc++.h>
using namespace std;
long long r, x, y, x_, y_, ans;
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &r, &x, &y, &x_, &y_);
  x = abs(x - x_);
  y = abs(y - y_);
  r *= 2;
  ans = ceil(sqrt(x * x + y * y) / r);
  printf("%I64d", ans);
}
