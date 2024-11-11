#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[19];
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  scanf("%d %d %d", &a[4], &a[5], &a[6]);
  scanf("%d %d %d", &a[7], &a[8], &a[9]);
  if ((a[0] + a[1] + a[4]) % 2 == 0) {
    a[10] == 1;
  } else {
    a[10] = 0;
  }
  if ((a[2] + a[1] + a[6]) % 2 == 0) {
    a[12] = 1;
  } else {
    a[12] = 0;
  }
  if ((a[9] + a[8] + a[6]) % 2 == 0) {
    a[18] == 1;
  } else {
    a[18] = 0;
  }
  if ((a[7] + a[4] + a[8]) % 2 == 0) {
    a[16] = 1;
  } else {
    a[16] = 0;
  }
  if ((a[1] + a[0] + a[2] + a[5]) % 2 == 0) {
    a[11] = 1;
  } else {
    a[11] = 0;
  }
  if ((a[8] + a[7] + a[9] + a[5]) % 2 == 0) {
    a[17] = 1;
  } else {
    a[17] = 0;
  }
  if ((a[4] + a[5] + a[0] + a[7]) % 2 == 0) {
    a[13] = 1;
  } else {
    a[13] = 0;
  }
  if ((a[6] + a[5] + a[2] + a[9]) % 2 == 0) {
    a[15] = 1;
  } else {
    a[15] = 0;
  }
  if ((a[4] + a[1] + a[5] + a[6] + a[8]) % 2 == 0) {
    a[14] = 1;
  } else {
    a[14] = 0;
  }
  printf("%d%d%d\n", a[10], a[11], a[12]);
  printf("%d%d%d\n", a[13], a[14], a[15]);
  printf("%d%d%d\n", a[16], a[17], a[18]);
  return 0;
}
