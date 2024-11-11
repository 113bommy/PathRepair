#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  if ((int)sqrt(a) > (int)((double)(sqrt(1. + 4 * 1. * b) - 1.) / 2.0)) {
    printf("Valera\n");
  } else
    printf("Vladik\n");
  return 0;
}
