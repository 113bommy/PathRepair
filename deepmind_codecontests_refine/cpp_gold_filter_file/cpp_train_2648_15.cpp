#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
int beat1(int x, int y) {
  if (b[3] > x && a[4] > y) return 1;
  if (b[4] > x && a[3] > y) return 1;
  if (b[3] < x && a[4] < y && b[4] < x && a[3] < y) return -1;
  return 0;
}
int main() {
  while (scanf("%d%d%d%d%d%d%d%d", &a[1], &b[1], &a[2], &b[2], &a[3], &b[3],
               &a[4], &b[4]) != EOF) {
    int b1 = beat1(a[1], b[2]);
    int b2 = beat1(a[2], b[1]);
    if (b1 == -1 || b2 == -1)
      printf("Team 1\n");
    else if (b1 == 1 && b2 == 1)
      printf("Team 2\n");
    else
      printf("Draw\n");
  }
}
