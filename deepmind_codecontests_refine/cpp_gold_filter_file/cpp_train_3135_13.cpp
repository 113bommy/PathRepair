#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%I64d%I64d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1)
    printf("%d", m - min(m % 6, 6 - m % 6));
  else if (n == 2) {
    if (m == 2)
      printf("0");
    else if (m == 3 || m == 7)
      printf("%I64d", n * m - 2);
    else
      printf("%I64d", n * m);
  } else if (n & 1 && m & 1)
    printf("%I64d", n * m - 1);
  else
    printf("%I64d", n * m);
  return 0;
}
