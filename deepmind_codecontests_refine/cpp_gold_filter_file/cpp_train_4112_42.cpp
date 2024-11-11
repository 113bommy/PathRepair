#include <bits/stdc++.h>
using namespace std;
long long n, i, ans, cnt, x;
int main() {
  scanf("%I64d", &n);
  cnt = 1;
  x = 1;
  while (i < n) {
    if (i * 10 + 9 <= n)
      ans += 9 * x * cnt;
    else
      ans += (n - i) * cnt;
    x *= 10;
    cnt++;
    i = i * 10 + 9;
  }
  printf("%I64d\n", ans);
  return 0;
}
