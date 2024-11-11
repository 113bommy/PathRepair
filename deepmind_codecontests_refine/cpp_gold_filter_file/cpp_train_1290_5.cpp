#include <bits/stdc++.h>
using namespace std;
long long x, y, m, pre;
long long step(long long x, long long y) {
  if (y >= m) return 0;
  if (y <= 0) return -1;
  long long tmp, num = 0;
  if (x) {
    if (x < 0) {
      num = abs(x / y);
      tmp = x + y * num + 2 * y;
      num += 2;
    } else {
      num++;
      tmp = x + y;
    }
  } else {
    num += 2;
    tmp = x + 2 * y;
  }
  x = min(tmp, y);
  y = max(tmp, y);
  return step(x, y) + num;
}
int main(void) {
  while (3 == scanf("%I64d%I64d%I64d", &x, &y, &m)) {
    if (x > y) swap(x, y);
    long long ans = step(x, y);
    printf("%I64d\n", ans);
  }
  return 0;
}
