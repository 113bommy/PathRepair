#include <bits/stdc++.h>
using namespace std;
char str[120][120];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) scanf("%s", str[i]);
  int res = 0, j1, j2;
  for (i = 0; i < n; i++) {
    for (j1 = 0; j1 < n; j1++)
      for (j2 = j1 + 1; j2 < n; j2++)
        if (str[i][j1] == str[i][j2] && str[i][j1] == 'C') res++;
    for (j1 = 0; j1 < n; j1++)
      for (j2 = j1 + 1; j2 < n; j2++)
        if (str[j1][i] == str[j2][i] && str[i][j1] == 'C') res++;
  }
  printf("%d\n", res);
  return 0;
}
