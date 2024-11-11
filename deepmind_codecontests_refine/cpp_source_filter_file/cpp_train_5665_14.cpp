#include <bits/stdc++.h>
int main() {
  int numDominos, d1, d2, eveneven = 0, evenodd = 0, oddeven = 0, oddodd = 0;
  scanf("%d", &numDominos);
  for (int i = 0; i < numDominos; i++) {
    scanf("%d %d", &d1, &d2);
    if (d1 % 2 == 0) {
      if (d2 % 2 == 0)
        eveneven++;
      else
        evenodd++;
    } else {
      if (d2 % 2 == 0)
        oddeven++;
      else
        oddodd++;
    }
  }
  if ((oddodd + evenodd) % 2 == 0 && (oddodd + oddeven) % 2 == 0) {
    printf("%d", 0);
  } else if ((oddodd + evenodd) % 2 != 0 && (oddodd + oddeven) % 2 == 0) {
    printf("%d", -1);
  } else if ((oddodd + evenodd) % 2 == 0 && (oddodd + oddeven) % 2 != 0) {
    printf("%d", -1);
  } else {
    if (evenodd != 0 && oddeven != 0)
      printf("%d", 1);
    else
      printf("%d", -1);
  }
  return 0;
}
