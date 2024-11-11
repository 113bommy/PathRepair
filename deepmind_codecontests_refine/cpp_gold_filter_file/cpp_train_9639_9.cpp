#include <bits/stdc++.h>
int cielTurn(int *tens, int *hds) {
  int sum = 0;
  while (sum + 100 <= 220 && *tens > 0) {
    sum += 100;
    *tens -= 100;
  }
  while (sum < 220 && *hds > 0) {
    sum += 10;
    *hds -= 10;
  }
  return sum;
}
int hanakoTurn(int *tens, int *hds) {
  int sum = 0;
  if (*hds >= 220) {
    sum = 220;
    *hds -= 220;
  } else if (*hds >= 120) {
    sum = 120;
    *hds -= 120;
  } else if (*hds >= 20) {
    sum = 20;
    *hds -= 20;
  }
  while (sum < 220 && *tens > 0) {
    sum += 100;
    *tens -= 100;
  }
  return sum;
}
int main() {
  int T, H;
  int turn = 0, res = 0;
  scanf("%d %d", &H, &T);
  H *= 100;
  T *= 10;
  do {
    turn = !turn;
    res = turn ? cielTurn(&H, &T) : hanakoTurn(&H, &T);
  } while (res == 220);
  printf("%s\n", !turn ? "Ciel" : "Hanako");
  return 0;
}
