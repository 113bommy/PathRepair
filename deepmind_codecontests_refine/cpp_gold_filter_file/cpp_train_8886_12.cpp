#include <bits/stdc++.h>
int main() {
  int n, k = 0;
  char x[80];
  scanf("%d", &n);
  scanf("%s", &x);
  for (int i = 0; i < n; i++) {
    if (x[i] == x[i + 1]) k++;
  }
  printf("%d", k);
  return 0;
}
