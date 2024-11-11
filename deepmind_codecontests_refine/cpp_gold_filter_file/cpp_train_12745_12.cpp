#include <bits/stdc++.h>
using namespace std;
int abs(int x) { return x < 0 ? -x : x; }
char a[51];
int main() {
  int a, p, k, i;
  scanf("%d %d %d", &a, &p, &k);
  if (p < 1 || p > a)
    return 0;
  else {
    if ((p - k) > 0) {
      if (p - k != 1) printf("<< ");
      for (i = k; i > 0; i--) printf("%d ", p - i);
    } else {
      for (i = 1; i < p; i++) printf("%d ", i);
    }
    printf("(%d) ", p);
    if ((p + k) < a) {
      for (i = 1; i <= k; i++) printf("%d ", p + i);
      printf(">>");
    } else {
      for (i = p + 1; i <= a; i++) printf("%d ", i);
    }
    return 0;
  }
}
