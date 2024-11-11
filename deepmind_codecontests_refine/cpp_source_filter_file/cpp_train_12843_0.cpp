#include <bits/stdc++.h>
using namespace std;
char a[15];
int main() {
  int n, k, i, l, j, f, m = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%s", a);
    l = strlen(a);
    f = 0;
    for (j = 0; j < l; j++) {
      if (a[i] == '4' || a[i] == 7) {
        f++;
      }
    }
    if (f <= k) {
      m++;
    }
  }
  printf("%d", m);
  return 0;
}
