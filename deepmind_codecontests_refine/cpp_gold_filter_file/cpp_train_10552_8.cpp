#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, n, q = 0, k;
  char a[105];
  scanf("%s", a);
  n = strlen(a);
  for (i = 0; i < n; i++) {
    for (k = i + 1; k < n; k++) {
      if (a[k] == a[i]) {
        for (j = k + 1, m = i + 1; j < n, m < n; j++, m++) {
          if (a[j] != a[m]) break;
        }
        q = max(j - k, q);
      }
    }
  }
  printf("%d\n", q);
  return 0;
}
