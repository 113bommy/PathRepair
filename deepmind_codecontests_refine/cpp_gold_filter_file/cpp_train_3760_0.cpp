#include <bits/stdc++.h>
using namespace std;
int n, A, B;
char s[10];
int main() {
  scanf("%d", &n);
  printf("0 0\n");
  fflush(stdout);
  scanf("%s", s);
  if (s[0] == 'w')
    A = 0;
  else
    A = 1;
  int l = 2, r = 999999998, mid, ans = 1;
  for (int i = 1; i < n; i++) {
    mid = (l + r) >> 1;
    printf("0 %d\n", mid);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'w')
      B = 0;
    else
      B = 1;
    if (B == A) {
      l = mid + 1;
      ans = l;
    } else {
      r = mid - 1;
      ans = r;
    }
  }
  printf("1 %d 3 %d\n", ans + 1, ans + 2);
  fflush(stdout);
  return 0;
}
