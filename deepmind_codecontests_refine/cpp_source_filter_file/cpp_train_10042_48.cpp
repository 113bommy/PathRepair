#include <bits/stdc++.h>
int main() {
  int n, i, sw;
  while (scanf("%d", &n) != EOF) {
    sw = 0;
    for (i = 1; i < n / 2; i++)
      if (i * (i + 2) / 2 == n) sw = 1;
    if (sw == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
