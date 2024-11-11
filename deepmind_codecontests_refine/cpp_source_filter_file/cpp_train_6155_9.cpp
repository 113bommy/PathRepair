#include <bits/stdc++.h>
int main() {
  long long n, x, y;
  scanf("%I64d", &n);
  scanf("%I64d %I64d", &x, &y);
  if ((((x) > (y)) ? (x) : (y)-1) > (n - ((x) < (y)) ? (x) : (y))) {
    printf("Black\n");
  } else {
    printf("White\n");
  }
  return 0;
}
