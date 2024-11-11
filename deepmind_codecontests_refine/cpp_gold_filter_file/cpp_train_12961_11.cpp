#include <bits/stdc++.h>
int main() {
  long long x, y, i;
  std::vector<long long> a;
  scanf("%I64d %I64d", &x, &y);
  if (x > y)
    i = 1;
  else
    i = -1;
  while (x != y) {
    long long j;
    if (x > y) {
      j = x / y;
      x %= y;
      if (x == 0) {
        x = y;
        j--;
      }
    } else {
      j = y / x;
      y %= x;
      if (y == 0) {
        y = x;
        j--;
      }
    }
    a.push_back(j);
  }
  if (x != 1)
    printf("Impossible");
  else
    for (int j = 0; j < a.size(); j++) {
      if (i == 1)
        printf("%I64dA", a[j]);
      else
        printf("%I64dB", a[j]);
      i = -i;
    }
  return 0;
}
