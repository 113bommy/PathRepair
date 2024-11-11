#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    int L, v, l, r;
    scanf("%d %d %d %d", &L, &v, &l, &r);
    printf("%d\n", L / v - (r / v - (l / v + (l % v > 0)) + 1));
  }
  return 0;
}
