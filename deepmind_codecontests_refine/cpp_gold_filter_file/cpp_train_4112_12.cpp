#include <bits/stdc++.h>
long long int array[] = {0,      1,       10,       100,       1000,      10000,
                         100000, 1000000, 10000000, 100000000, 1000000000};
long long int total[] = {0,      9,       90,       900,       9000,      90000,
                         900000, 9000000, 90000000, 900000000, 9000000000};
long long int digit[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int main() {
  long long int n, p;
  long long int count = 0, i;
  scanf("%I64d", &n);
  p = n;
  while (n > 0) {
    n = n / 10;
    count++;
  }
  long long int answer = 0;
  for (i = 1; i < count; i++) {
    answer = answer + (total[i] * digit[i]);
  }
  answer = answer + (p - array[count] + 1) * digit[count];
  printf("%I64d", answer);
  return 0;
}
