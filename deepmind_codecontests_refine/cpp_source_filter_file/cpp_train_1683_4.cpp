#include <bits/stdc++.h>
int main() {
  long long k;
  scanf("%lld", &k);
  if (k <= 9) {
    printf("%d", k);
    return 0;
  }
  long long cur = 1, cnt = 9;
  while (k > 0) {
    if (cur * cnt > k) break;
    k -= cur * cnt, cnt *= 10;
    ++cur;
  }
  long long mod = k % cur, a = (k - 1) / cur;
  if (mod == 0) mod = cur;
  long long num = 1;
  for (int i = 1; i < cur; ++i) num *= 10;
  num += a;
  for (int i = 1; i <= (cur - mod); ++i) num /= 10;
  printf("%lld", num % 10);
  return 0;
}
