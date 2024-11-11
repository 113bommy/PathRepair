#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, x, flag, var, k = 0;
  scanf("%d", &n);
  char olds[n][30], news[n][30];
  for (i = 0; i < n; i++) {
    char a[30], b[30];
    flag = 0;
    var = 0;
    scanf("%s", a);
    scanf("%s", b);
    for (j = 0; j < k; j++) {
      if (!strcmp(a, news[j])) {
        flag = 1;
        break;
      }
    }
    for (x = 0; x < k; x++) {
      if (!strcmp(b, olds[x])) {
        var = 1;
        break;
      }
    }
    if (flag == 0 && var == 0) {
      strcpy(olds[k], a);
      strcpy(news[k], b);
      k++;
    }
    if (flag == 1 && var == 0) strcpy(news[j], b);
  }
  cout << k - 1 << endl;
  for (i = 0; i < k; i++) {
    cout << olds[i] << " " << news[i] << endl;
  }
  return 0;
}
