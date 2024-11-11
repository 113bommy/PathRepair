#include <bits/stdc++.h>
using namespace std;
int n, T, a[10101];
int Query(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
void Print(int *a) {
  printf("! ");
  for (int i = 1; i <= n; i++) {
    printf("%d", a[i]);
  }
  puts("");
}
int main(void) {
  scanf("%d%d", &n, &T);
  int all = 0;
  for (int i = n; i > 1; i--) {
    a[i] = -1;
    for (int j = 0; j < 20; j++) {
      Query(1, i - 1);
      int x = Query(1, i - 1);
      if (x != T) {
        a[i] = (all + 1 - (n - i - all)) == T - x;
        all += a[i];
        while (x != T) {
          Query(1, i - 1);
          x = Query(1, i - 1);
        }
        break;
      }
    }
    if (!~a[i]) {
      a[i] = (n - i) - all > all ? 1 : 0;
      all += a[i];
    }
  }
  a[1] = T - all;
  Print(a);
  return 0;
}
