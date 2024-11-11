#include <bits/stdc++.h>
using namespace std;
int n, a[10], s, x;
bool flag;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x), a[x]++, s += x;
  if (!a[0])
    printf("-1\n");
  else {
    if (s % 3 == 1) {
      if (a[1])
        a[1]--, flag = 1;
      else if (a[4])
        a[4]--, flag = 1;
      else if (a[7])
        a[7]--, flag = 1;
      else if (a[2] > 1)
        a[2] -= 2, flag = 1;
      else if (a[2] == 1) {
        a[2]--;
        if (a[5])
          a[5]--, flag = 1;
        else if (a[8])
          a[8]--, flag = 1;
      } else {
        if (a[5] > 1)
          a[5] -= 2, flag = 1;
        else if (a[5] == 1 && a[8])
          a[5]--, a[8]--, flag = 1;
        else if (a[8] > 1)
          a[8] -= 2, flag = 1;
      }
    } else if (s % 3 == 2) {
      if (a[2])
        a[2]--, flag = 1;
      else if (a[5])
        a[5]--, flag = 1;
      else if (a[8])
        a[8]--, flag = 1;
      else if (a[1] > 1)
        a[1] -= 2, flag = 1;
      else if (a[1] == 1) {
        a[1]--;
        if (a[4])
          a[4]--, flag = 1;
        else if (a[7])
          a[7]--, flag = 1;
      } else {
        if (a[4] > 1)
          a[4] -= 2, flag = 1;
        else if (a[4] == 1 && a[7])
          a[4]--, a[7]--, flag = 1;
        else if (a[7] > 1)
          a[7] -= 2, flag = 1;
      }
    } else if (s % 3 == 0)
      flag = 1;
    if (flag) {
      for (int i = 1; i <= 9; i++)
        if (a[i]) flag = 0;
      if (!flag) {
        for (int i = 9; i >= 0; i--)
          for (int j = 1; j <= a[i]; j++) printf("%d", i);
      } else
        printf("0\n");
    } else
      printf("0\n");
  }
  return 0;
}
