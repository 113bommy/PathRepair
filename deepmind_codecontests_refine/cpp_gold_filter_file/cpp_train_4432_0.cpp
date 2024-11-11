#include <bits/stdc++.h>
int main() {
  long long int n, i;
  char ch;
  scanf("%I64d%c", &n, &ch);
  char a[] = {'f', 'e', 'd', 'a', 'b', 'c'};
  long long int sum = 0;
  if (n % 4 == 1) sum = n + 12 * (n / 4);
  if (n % 4 == 2) sum = n + 12 * (n / 4) + 6;
  if (n % 4 == 3) sum = (n - 2) + 12 * ((n - 2) / 4);
  if (n % 4 == 0) sum = (n - 2) + 12 * ((n - 2) / 4) + 6;
  for (i = 0; i < 6; i++) {
    if (ch == a[i]) {
      sum = sum + i;
    }
  }
  printf("%I64d", sum);
}
