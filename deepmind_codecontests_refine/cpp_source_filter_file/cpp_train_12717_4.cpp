#include <bits/stdc++.h>
using namespace std;
int num[300002];
int main(void) {
  int a, b, i, l, r, m, flag, now;
  scanf("%d %d", &a, &b);
  for (i = 0; i < a; i++) {
    scanf("%d", &num[i]);
  }
  l = 0;
  r = a - 1;
  while (l < r) {
    m = (l + r) >> 1;
    flag = 1;
    for (i = 0; i < a; i++) {
      if (i) {
        if (num[i] < now) {
          if (num[i] + m < now) {
            flag = 0;
            break;
          }
        } else if (num[i] > now) {
          if (num[i] + m >= b) {
            if ((num[i] + m) % b < now) {
              now = num[i];
            }
          } else {
            if (num[i] + m < now) {
              flag = 0;
              break;
            } else {
              now = num[i];
            }
          }
        }
      } else {
        if (num[i] + m >= b) {
          now = 0;
        } else {
          now = num[i];
        }
      }
    }
    if (flag) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
