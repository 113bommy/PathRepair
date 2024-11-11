#include <bits/stdc++.h>
using namespace std;
int ary[4];
int sum;
int main() {
  while (~scanf("%d%d%d", &ary[1], &ary[2], &ary[3])) {
    sum = 0;
    for (int i = 1; i <= 3; i++) {
      if (ary[i] != 0) {
        if (ary[i] % 3 == 0) {
          sum += ary[i] / 3;
          sum--;
          ary[i] = 3;
        } else {
          sum += ary[i] / 3;
          ary[i] %= 3;
        }
      }
    }
    int count = 0;
    for (int i = 1; i <= 3; i++) {
      if (ary[i] == 3) count++;
    }
    if (count == 3)
      printf("%d\n", sum + 3);
    else if (count == 2) {
      printf("%d\n", sum + 2);
    } else if (count == 1) {
      int num = 0;
      for (int i = 1; i <= 3; i++) {
        if (ary[i] == 2) num++;
      }
      if (num == 2)
        printf("%d\n", sum + 2);
      else
        printf("%d]\n", sum + 1);
    } else {
      int min = 10;
      for (int i = 1; i <= 3; i++) {
        if (min > ary[i]) min = ary[i];
      }
      printf("%d\n", sum + min);
    }
  }
}
