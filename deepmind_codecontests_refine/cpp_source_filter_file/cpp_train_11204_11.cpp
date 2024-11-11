#include <bits/stdc++.h>
using namespace std;
unsigned int a[301000], n, i, temp, stat, j, x;
unsigned int newstat() {
  stat--;
  while (1) {
    if (a[stat]) {
      x = n - stat - 1;
      return 0;
    }
    stat--;
  }
}
int main() {
  scanf("%u", &n);
  ;
  printf("1 ");
  stat = n;
  x = -1;
  for (i = 1; i < n; i++) {
    scanf("%u", &temp);
    ;
    if (temp == stat)
      newstat();
    else
      a[temp] = 1;
    printf("%u ", i - x);
    ;
  }
  printf("1\n");
  return 0;
}
