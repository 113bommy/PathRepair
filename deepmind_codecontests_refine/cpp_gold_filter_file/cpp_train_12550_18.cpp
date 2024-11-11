#include <bits/stdc++.h>
int main() {
  int n, a, b, c, wordsCount = 1;
  scanf("%d%d%d", &n, &c, &a);
  for (int i = 1; i < n; i++) {
    scanf("%d", &b);
    if (b - a > c)
      wordsCount = 1;
    else
      wordsCount++;
    a = b;
  }
  printf("%d\n", wordsCount);
}
