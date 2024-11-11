#include <bits/stdc++.h>
using namespace std;
int x[1010], y[1010];
int n;
int timhuong(int a1, int a2) {
  if (x[a1] == x[a2]) {
    if (y[a1] < y[a2]) {
      return 0;
    }
    return 2;
  }
  if (x[a1] < x[a2]) {
    return 1;
  }
  return 3;
}
int check(int a) {
  int bien1, bien2;
  bien1 = timhuong(a - 1, a);
  bien2 = timhuong(a, a + 1);
  if ((bien1 == 0 && bien2 == 3) || (bien1 == 1 && bien2 == 0) ||
      (bien1 == 2 && bien2 == 1) || (bien1 == 3 && bien2 == 2)) {
    return 1;
  }
  return 0;
}
void xuly() {
  int i, dem;
  dem = 0;
  for (i = 1; i < n; i++) {
    if (check(i) == 1) {
      dem++;
    }
  }
  printf("%d\n", dem);
}
int main() {
  int i;
  while (scanf("%d", &n) > 0) {
    for (i = 0; i <= n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    xuly();
  }
  return 0;
}
