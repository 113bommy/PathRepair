#include <bits/stdc++.h>
int main() {
  int t, n;
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    int res = n / 4 * 2;
    if (n % 4 == 3) res++;
    if (n <= 2)
      printf("0\n");
    else
      printf("%d\n", n / 2);
  }
}
