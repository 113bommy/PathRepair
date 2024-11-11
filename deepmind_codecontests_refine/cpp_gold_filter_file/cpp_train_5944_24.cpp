#include <bits/stdc++.h>
int main() {
  int i, j;
  scanf("%d", &i);
  while (i > 0) {
    scanf("%d", &j);
    if (j % 2) j++;
    j--;
    printf("%d ", j);
    i--;
  }
  puts("");
}
