#include <bits/stdc++.h>
using namespace std;
long long b, d, x;
int Dfs(long long x) {
  int i;
  long long tmp;
  for (i = 1, tmp = b; i <= 7; i++, tmp *= b)
    if (tmp % x == 0) return 1;
  if (b % x == 1) return 1;
  if (b % x == x - 1) return 1;
  return 0;
}
int main() {
  int i, j;
  long long tmp;
  scanf("%I64d %I64d", &b, &d);
  for (i = 1, tmp = b; i <= 7; i++, tmp *= b)
    if (tmp % d == 0) {
      printf("2-type\n%d\n", i);
      ;
      exit(0);
    }
  if (b % d == 1) {
    printf("3-type\n");
    ;
    exit(0);
  }
  if (b % d == d - 1) {
    printf("11-type\n");
    ;
    exit(0);
  }
  for (i = 2; i <= d; i++) {
    for (tmp = i; d % tmp == 0; tmp *= i)
      ;
    if (tmp == i) continue;
    if (!Dfs(tmp / i)) break;
    d /= tmp / i;
  }
  if (d == 1) {
    printf("6-type\n");
    ;
    exit(0);
  } else {
    printf("7-type\n");
    ;
    exit(0);
  }
}
