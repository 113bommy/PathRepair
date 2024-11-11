#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t, i;
  scanf("%I64d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%I64d", &n);
    if (n % 2 == 0)
      printf("%I64d\n", 4 * n + 1);
    else if ((n + 1) % 4 == 0)
      printf("%I64d", n + 1);
    else
      printf("%I64d\n", 2 * n + 1);
  }
  return 0;
}
