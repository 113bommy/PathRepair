#include <bits/stdc++.h>
int main() {
  int n, sum, i;
  scanf("%d", &n);
  char str[n];
  scanf("%s", str);
  sum = 2;
  for (i = 0; i < n; i = sum) {
    printf("%c", str[i]);
    sum = sum + i;
  }
}
