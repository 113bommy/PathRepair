#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, j, i;
  char a[55][55];
  scanf("%d%d", &n, &m);
  for (i = (0); i < (n); i++)
    for (j = (0); j < (m); j++) a[i][j] = '.';
  int c = 1;
  for (int i = 0; i < n;) {
    if (i % 2 == 0) {
      for (j = (0); j < (m); j++) a[i][j] = '#';
      i++;
    } else {
      if (c)
        a[i][m - 1] = '#';
      else
        a[i][0] = '#';
      c = !c;
      i++;
    }
  }
  for (i = (0); i < (n); i++) {
    for (j = (0); j < (m); j++) cout << a[i][j];
    printf("\n");
  }
  return 0;
}
