#include <bits/stdc++.h>
int num[100100];
int n;
int main() {
  scanf("%d", &n);
  if (n % 4 != 0 && n % 4 != 1) {
    puts("-1");
    return 0;
  }
  if (n % 2 == 1) num[n / 2] = n / 2 + 1;
  for (int i = 0, j = 0; j < n - n % 2; i += 2, j += 4) {
    num[i] = 2 + j;
    num[i + 1] = n - j;
    num[n - 1 - i] = n - 1 - j;
    num[n - 2 - i] = 1 + j;
  }
  for (int i = 0; i < n; i++) printf("%d ", num[i]);
  puts("");
  return 0;
}
