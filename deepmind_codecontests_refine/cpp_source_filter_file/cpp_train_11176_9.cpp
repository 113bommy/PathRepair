#include <bits/stdc++.h>
using namespace std;
int main() {
  double a1, b1, c1, a2, b2, c2;
  while (scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2) != EOF) {
    if (a1 == 0 && b1 == 0 && c1 == 0 || a2 == 0 && b2 == 0 && c2 == 0) {
      printf("0\n");
      break;
    }
    if (a1 * b2 == a2 * b1) {
      if (a1 == 0 && a2 == 0) {
        if (c1 * b2 == c2 * b1)
          printf("-1\n");
        else
          printf("0\n");
      } else {
        if (c1 * a2 == c2 * a1)
          printf("-1\n");
        else
          printf("0\n");
      }
    } else {
      printf("1\n");
    }
  }
  return 0;
}
