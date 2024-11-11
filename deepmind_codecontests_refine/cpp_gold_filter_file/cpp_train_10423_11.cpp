#include <bits/stdc++.h>
using namespace std;
char a[100010];
int main(void) {
  int n, i, j;
  while (scanf("%d", &n) == 1) {
    scanf("%s", a);
    a[n] = 'S';
    int cnt = 0;
    int t = 0;
    int pre = 0;
    int flag = 0;
    int maxn = 0;
    int maxt = 0;
    for (i = 0; i <= n; i++) {
      if (a[i] == 'G') {
        t++;
      } else {
        if (t != 0) {
          if (flag == 1) {
            maxt = max(maxt, pre + t);
          }
          pre = t;
          flag = 0;
          cnt++;
        }
        flag++;
        maxn = max(maxn, t);
        t = 0;
      }
    }
    if (cnt >= 3)
      printf("%d\n", max(maxn + 1, maxt + 1));
    else {
      if (cnt == 2)
        printf("%d\n", max(maxn + 1, maxt));
      else
        printf("%d\n", maxn);
    }
  }
  return 0;
}
