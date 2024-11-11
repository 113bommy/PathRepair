#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
int main(int argc, char** argv) {
  int k;
  cin >> k;
  printf("+------------------------+\n|");
  for (int i = 1; i <= 31; i += 3) {
    if ((i <= k - 1 && i > 1) || (i <= k && i == 1)) {
      printf("O.");
    } else {
      printf("#.");
    }
  }
  printf("|D|)\n|");
  for (int i = 2; i <= 32; i += 3) {
    if ((i <= k - 1 && i > 2) || (i <= k && i == 2)) {
      printf("O.");
    } else {
      printf("#.");
    }
  }
  printf("|.|\n|");
  if (k >= 3) {
    printf("O.......................");
  } else {
    printf("#.......................");
  }
  printf("|\n|");
  for (int i = 4; i <= 34; i += 3) {
    if ((i <= k && i > 4) || (i <= k && i == 4)) {
      printf("O.");
    } else {
      printf("#.");
    }
  }
  printf("|.|)\n+------------------------+");
  return 0;
}
