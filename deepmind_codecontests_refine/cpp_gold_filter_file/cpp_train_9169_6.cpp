#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int values[101] = {0};
  int coins[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &coins[i]);
    values[coins[i]]++;
  }
  int max = values[1];
  for (int i = 1; i < 100; i++) {
    if (values[i + 1] > max) max = values[i + 1];
  }
  printf("%d", max);
  return 0;
}
