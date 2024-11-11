#include <bits/stdc++.h>
using namespace std;
long long a, b, ans;
int main() {
  scanf("%I64d%I64d", &a, &b);
  while (b != 1 && a != 1) {
    if (a > b) {
      ans += a / b;
      a %= b;
    } else {
      ans += b / a;
      b %= a;
    }
  }
  if (a == 1)
    printf("%I64d\n", ans + b);
  else
    printf("%I64d\n", ans + a);
  return 0;
}
