#include <bits/stdc++.h>
int main() {
  int k, i;
  int n1, n2, n3, n4;
  int r, d;
  scanf("%d", &k);
  n1 = 0;
  n2 = 0;
  n3 = 0;
  n4 = 0;
  if (k >= 1) {
    n1 = 1;
  }
  if (k >= 2) n2 = 1;
  if (k >= 3) n3 = 1;
  if (k >= 4) n4 = 1;
  if (k > 4) {
    k = k - 4;
    r = k % 3;
    d = k / 3;
    n1 += d;
    n2 += d;
    n4 += d;
    if (r >= 1) n1++;
    if (r >= 2) n2++;
  }
  printf("+");
  for (i = 0; i < 24; i++) printf("%c", '-');
  printf("+");
  printf("\n");
  printf("|");
  for (i = 0; i < n1; i++) printf("O.");
  for (i = 0; i < 11 - n1; i++) printf("#.");
  printf("|D|)");
  printf("\n");
  printf("|");
  for (i = 0; i < n2; i++) printf("O.");
  for (i = 0; i < 11 - n2; i++) printf("#.");
  printf("|.|");
  printf("\n");
  printf("|");
  if (n3 == 1)
    printf("O");
  else
    printf("#");
  for (i = 0; i < 23; i++) printf(".");
  printf("|\n");
  printf("|");
  for (i = 0; i < n4; i++) printf("O.");
  for (i = 0; i < 11 - n4; i++) printf("#.");
  printf("|.|)\n");
  printf("+");
  for (i = 0; i < 24; i++) printf("-");
  printf("+");
  printf("\n");
  return 0;
}
