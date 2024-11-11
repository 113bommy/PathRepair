#include <bits/stdc++.h>
using namespace std;
int x[8], y[8];
int main() {
  int firstx = -1;
  int secondx = -1;
  int thirdx = -1;
  int firsty = -1;
  int secondy = -1;
  int thirdy = -1;
  int flag = 0;
  for (int i = 0; i < 8; i++) {
    scanf("%d %d", &x[i], &y[i]);
    if (x[i] == firstx || x[i] == secondx || x[i] == thirdx)
      ;
    else if (firstx == -1)
      firstx = x[i];
    else if (secondx == -1) {
      secondx = x[i];
      if (firstx > secondx) firstx ^= secondx ^= firstx ^= secondx;
    } else if (thirdx == -1) {
      thirdx = x[i];
      if (secondx > thirdx) thirdx ^= secondx ^= thirdx ^= secondx;
      if (firstx > secondx) firstx ^= secondx ^= firstx ^= secondx;
    } else
      flag = 1;
    if (y[i] == firsty || y[i] == secondy || y[i] == thirdy)
      ;
    else if (firsty == -1)
      firsty = y[i];
    else if (secondy == -1) {
      secondy = y[i];
      if (firsty > secondy) firsty ^= secondy ^= firsty ^= secondy;
    } else if (thirdy == -1) {
      thirdy = y[i];
      if (secondy > thirdy) thirdy ^= secondy ^= thirdy ^= secondy;
      if (firsty > secondy) firsty ^= secondy ^= firsty ^= secondy;
    } else
      flag = 1;
  }
  if (flag || thirdx == -1 || thirdy == -1) {
    puts("ugly");
    return 0;
  }
  int i, last = 0;
  for (i = 0; i < 8; i++) {
    if (x[i] == secondx && y[i] == secondy) last = 1;
    if (x[i] != firstx && x[i] != thirdx && x[i] != secondx) last = 1;
    if (y[i] != firsty && y[i] != thirdy && y[i] != secondy) last = 1;
  }
  if (last) {
    puts("ugly");
    return 0;
  }
  int sd = 0;
  for (i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++)
      if (x[i] == x[j] && y[i] == y[j]) {
        sd = 1;
        break;
      }
    if (sd == 1) break;
  }
  if (sd == 1) {
    puts("ugly");
    return 0;
  }
  puts("respectable");
}
