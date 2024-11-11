#include <bits/stdc++.h>
int main() {
  int num, i, bills = 0, rem;
  scanf("%d", &num);
  if (num >= 100) {
    rem = num / 100;
    num = num - (100 * rem);
    bills = bills + (rem);
  }
  if (num >= 20) {
    rem = num / 20;
    num = num - (20 * rem);
    bills = bills + (rem);
  }
  if (num >= 10) {
    rem = num / 10;
    num = num - (10 * rem);
    bills = bills + (rem);
  }
  if (num >= 5) {
    rem = num / 5;
    num = num - (5 * rem);
    bills = bills + (rem);
  }
  if (num > 1) {
    rem = num / 1;
    num = num - (1 * rem);
    bills = bills + (rem);
  }
  printf("%d", bills);
}
