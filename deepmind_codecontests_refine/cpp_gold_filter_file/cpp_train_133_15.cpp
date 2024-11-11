#include <bits/stdc++.h>
int main() {
  long long n;
  scanf("%I64d", &n);
  if (n == 1) {
    printf("1\n0");
    return 0;
  }
  long long k = n;
  int cnt = 0, t = 0;
  long long move = 1;
  for (long long i = 2; i * i <= n; ++i)
    while (n % i == 0) {
      cnt++;
      n /= i;
      if (t < 2) {
        move *= i;
        t++;
      }
    }
  if (n > 1) ++cnt;
  if ((t == 2) && cnt >= 3)
    printf("1\n%I64d", move);
  else if (t == 0)
    printf("1\n0");
  else
    printf("2");
  return 0;
}
