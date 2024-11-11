#include <bits/stdc++.h>
using namespace std;
int a, b, c, l;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &l);
  long long ans = 0;
  int i;
  for (i = 0; i <= l; i++) ans += (long long)(i + 1) * (i + 2) / 2;
  long long num = 0;
  for (i = 0; i <= l; i++) {
    if (b + c <= a + i) {
      num = min(l - i, a + i - b - c);
      ans -= (num + 1) * (num + 2) / 2;
    }
    if (a + c <= b + i) {
      num = min(l - i, b + i - a - c);
      ans -= (num + 1) * (num + 2) / 2;
    }
    if (a + b <= c + i) {
      num = min(l - i, c + i - a - b);
      ans -= (num + 1) * (num + 2) / 2;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
