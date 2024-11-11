#include <bits/stdc++.h>
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n < 4 and n != 3) {
      puts("-1");
      continue;
    }
    if (n % 3 == 0)
      printf("%d 0 0\n", n / 3);
    else if ((n - 5) % 3 == 0)
      printf("%d 1 0\n", (n - 5) / 3);
    else if ((n - 7) % 3 == 0)
      printf("%d 0 1\n", (n - 7) / 3);
  }
  return 0;
}
