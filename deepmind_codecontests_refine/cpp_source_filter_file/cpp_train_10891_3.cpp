#include <bits/stdc++.h>
using namespace std;
int n, cnt1;
bool ok(int l, int r) {
  printf("? ");
  for (int i = 0; i < l; i++) {
    printf("0");
  }
  for (int i = l; i <= r; i++) {
    printf("1");
  }
  for (int i = r + 1; i <= n - 1; i++) {
    printf("0");
  }
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  int len = r - l + 1;
  if (abs(cnt1 - x) == len)
    return false;
  else
    return true;
}
int main() {
  scanf("%d", &n);
  int l = 0, r = n - 1;
  printf("? ");
  for (int i = l; i <= r; i++) {
    printf("0");
  }
  printf("\n");
  fflush(stdout);
  scanf("%d", &cnt1);
  while ((r - l) > 1) {
    int mid = (l + r) >> 1;
    if (ok(mid, r)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("? ");
  for (int i = 0; i < l; i++) {
    printf("0");
  }
  for (int i = l; i < r; i++) {
    printf("1");
  }
  for (int i = r; i <= n - 1; i++) {
    printf("0");
  }
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  printf("! ");
  if (cnt1 > x) {
    printf("%d %d\n", l + 1, r + 1);
  } else {
    printf("%d %d\n", r + 1, l + 1);
  }
  return 0;
}
