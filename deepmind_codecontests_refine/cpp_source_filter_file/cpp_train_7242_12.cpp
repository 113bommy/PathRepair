#include <bits/stdc++.h>
int main() {
  char kata[100555];
  gets(kata);
  int len = strlen(kata);
  int count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0,
      count6 = 0, count7 = 0;
  for (int i = 0; i < len; i++) {
    if (kata[i] == 'B') {
      count1++;
    }
    if (kata[i] == 'u') {
      count2++;
    }
    if (kata[i] == 'l') {
      count3++;
    }
    if (kata[i] == 'b') {
      count4++;
    }
    if (kata[i] == 'a') {
      count5++;
    }
    if (kata[i] == 's') {
      count6++;
    }
    if (kata[i] == 'r') {
      count7++;
    }
  }
  if (count1 == 0 || count2 == 0 || count3 == 0 || count4 == 0 || count5 == 0 ||
      count6 == 0 || count7 == 0) {
    count = 0;
    printf("0");
    return 0;
  }
  while (count1 > 0 && count2 > 0 && count3 > 0 && count4 > 0 && count5 > 0 &&
         count6 > 0 && count7 > 0) {
    count1--;
    count2 -= 2;
    count3--;
    count4--;
    count5 -= 2;
    count6--;
    count7--;
    count++;
    if (count1 == 0 || count2 == 0 || count3 == 0 || count4 == 0 ||
        count5 == 0 || count6 == 0 || count7 == 0) {
      printf("%d", count);
      return 0;
    }
  }
}
