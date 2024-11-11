#include <bits/stdc++.h>
int main() {
  int a, b, ans = 0;
  scanf("%d %d", &a, &b);
  if (a > b) {
    ans = (a - b) / 2;
    printf("%d %d", b, ans);
  } else if (a < b) {
    ans = (a - b) / 2;
    printf("%d %d", a, ans);
  } else if (a == b) {
    ans = (a - b) / 2;
    printf("%d %d", b, ans);
  }
  return 0;
}
