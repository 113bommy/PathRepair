#include <bits/stdc++.h>
char s[300009];
long long process() {
  long long count = 0;
  long long i = 0;
  long long tmp;
  for (; s[i]; i++) {
    if ((s[i] - '0') % 4 == 0) count++;
    tmp = 10 * (s[i - 1] - '0') + (s[i] - '0');
    if (tmp % 4 == 0) {
      count += i;
    }
  }
  return count;
}
int main() {
  scanf("%s", s);
  printf("%l64d\n", process());
  return 0;
}
