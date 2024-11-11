#include <bits/stdc++.h>
int main() {
  int a1, b1, a2, b2, a3, b3;
  scanf("%d %d", &a1, &b1);
  scanf("%d %d", &a2, &b2);
  scanf("%d %d", &a3, &b3);
  int flag = 0;
  if (a2 + a3 <= a1 && b2 <= b1 && b3 <= b1) {
    flag = 1;
  } else if (b2 + b3 <= b1 && a2 <= a1 && a3 <= a1) {
    flag = 1;
  } else if (a2 + a3 <= b1 && b2 <= a1 && b3 <= a2)
    flag = 1;
  else if (b2 + a3 <= b1 && a2 <= a1 && b3 <= a1)
    flag = 1;
  else if (a2 + b3 <= b1 && b2 <= a1 && a3 <= a1)
    flag = 1;
  else if (b2 + b3 <= a1 && a2 <= b1 && a3 <= b1)
    flag = 1;
  else if (b2 + a3 <= a1 && a2 <= b1 && b3 <= b1)
    flag = 1;
  else if (a2 + b3 <= a1 && b2 <= b1 && a3 <= b1)
    flag = 1;
  int temp = a1;
  a1 = b1;
  b1 = temp;
  if (a2 + a3 <= a1 && b2 <= b1 && b3 <= b1) {
    flag = 1;
  } else if (b2 + b3 <= b1 && a2 <= a1 && a3 <= a1) {
    flag = 1;
  } else if (a2 + a3 <= b1 && b2 <= a1 && b3 <= a2)
    flag = 1;
  else if (b2 + a3 <= b1 && a2 <= a1 && b3 <= a1)
    flag = 1;
  else if (a2 + b3 <= b1 && b2 <= a1 && a3 <= a1)
    flag = 1;
  else if (b2 + b3 <= a1 && a2 <= b1 && a3 <= b1)
    flag = 1;
  else if (b2 + a3 <= a1 && a2 <= b1 && b3 <= b1)
    flag = 1;
  else if (a2 + b3 <= a1 && b2 <= b1 && a3 <= b1)
    flag = 1;
  if (flag) {
    printf("YES\n");
  } else
    printf("NO\n");
  return 0;
}
