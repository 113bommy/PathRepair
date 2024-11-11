#include <bits/stdc++.h>
using namespace std;
int nToSeg[10];
int countSeg(char range[]) {
  char at = range[0];
  int i = 0;
  int acc = 0;
  while (at >= '0' && at <= '9') {
    acc += nToSeg[at - '0'];
    at = range[++i];
  }
  return acc;
}
int main() {
  nToSeg[0] = 6;
  nToSeg[1] = 2;
  nToSeg[2] = 5;
  nToSeg[3] = 5;
  nToSeg[4] = 4;
  nToSeg[5] = 5;
  nToSeg[6] = 6;
  nToSeg[7] = 3;
  nToSeg[8] = 7;
  nToSeg[9] = 8;
  char range[8];
  int a, b;
  scanf(" %d %d", &a, &b);
  int acc = 0;
  while (a <= b) {
    sprintf(range, "%d", a++);
    acc += countSeg(range);
  }
  printf("%d\n", acc);
  return 0;
}
