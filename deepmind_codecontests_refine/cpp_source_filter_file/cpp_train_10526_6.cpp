#include <bits/stdc++.h>
using namespace std;
int n, l, r, mid, rcol, col, pre;
char s[10];
int f(char c) {
  if (c == 'b') return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  l = -1e9;
  r = 1e9;
  printf("%d %d\n", r, 0);
  fflush(stdout);
  r--;
  l++;
  scanf("%s", s);
  rcol = f(s[0]);
  for (int i = 1; i < n; i++) {
    assert(l <= r);
    mid = (l + r + 1) / 2;
    printf("%d %d\n", mid, 0);
    fflush(stdout);
    scanf("%s", s);
    col = f(s[0]);
    if (col == rcol)
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d %d %d %d\n", l - 1, 1, r + 1, -1);
  fflush(stdout);
  return 0;
}
