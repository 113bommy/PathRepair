#include <bits/stdc++.h>
using namespace std;
long long a, l, r;
int main() {
  l = 0, r = 1000000000000000000LL - 1;
  scanf("%I64d", &a);
  long long ans = 45;
  for (int i = 1; i <= 17; i++) {
    long long tmp = 0;
    for (int j = 0; j < 10; j++) tmp = (tmp + ans) % a;
    ans = tmp;
  }
  long long tmp = 0;
  for (int j = 0; j < 18; j++) tmp = (tmp + ans) % a;
  ans = tmp;
  if (ans == 0)
    printf("%I64d %I64d\n", l, r);
  else
    printf("%I64d %I64d\n", a - ans, r + a - ans);
  return 0;
}
