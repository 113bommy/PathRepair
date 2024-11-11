#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &s);
  if (m > s) {
    puts("NO");
    return 0;
  }
  if ((n - 1) * m < s) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (n == 2) {
    for (int i = 1; i <= m; ++i)
      if ((i & 1) == 1)
        printf("2 ");
      else
        printf("1 ");
    return 0;
  }
  int i;
  long long S = s - m;
  for (i = 1; (long long)i <= S / (n - 2); ++i) {
    if ((i & 1) == 1)
      printf("%I64d ", n);
    else
      printf("1 ");
  }
  int ss = i;
  if (i & 1 == 1) {
    for (; i < (int)m; ++i)
      if ((i - ss & 1) == 1)
        printf("1 ");
      else
        printf("2 ");
    if (i == (int)m)
      printf("%I64d",
             (long long)S % (n - 2) + 1ll + ((long long)i - ss & 1) + 1ll);
  } else {
    for (; i < (int)m; ++i)
      if ((i - ss) & 1 == 1)
        printf("%I64d ", n);
      else
        printf("%I64d ", n - 1);
    if (i == (int)m)
      printf("%I64d",
             (long long)n - (S % (n - 2)) - ((long long)i - ss & 1) - 1ll);
  }
  return 0;
}
