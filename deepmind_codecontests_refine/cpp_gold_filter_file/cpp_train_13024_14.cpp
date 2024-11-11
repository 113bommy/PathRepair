#include <bits/stdc++.h>
int main() {
  int sum, num, min_coins;
  scanf("%d%d", &num, &sum);
  min_coins = sum / num;
  if (sum % num < num && sum % num != 0) {
    min_coins += 1;
  }
  printf("%d", min_coins);
  return 0;
}
