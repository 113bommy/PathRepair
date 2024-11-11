#include <bits/stdc++.h>
using namespace std;
int n;
char ch[100];
int main() {
  scanf("%d", &n);
  int l = 0, r = 1e9;
  for (int i = 1; i <= min(29, n); i++) {
    int mid = (l + r) >> 1;
    printf("%d %d\n", mid, 1);
    fflush(stdout);
    scanf("%s", ch);
    if (ch[0] == 'b')
      l = mid;
    else
      r = mid;
  }
  if (n <= 29) {
    printf("%d %d %d %d\n", l, 2, r, 0);
  } else {
    printf("%d %d\n", l, 10);
    fflush(stdout);
    scanf("%s", ch);
    if (ch[0] == 'b')
      printf("%d %d %d %d\n", l, 0, r, 2);
    else
      printf("%d %d %d %d\n", l, 2, r, 0);
  }
  fflush(stdout);
  return 0;
}
