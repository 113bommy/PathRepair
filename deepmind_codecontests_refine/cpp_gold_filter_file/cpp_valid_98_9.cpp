#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s + 1);
    int a[100] = {0}, b[100] = {0};
    int aa = 0, bb = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'a') {
        aa++;
        b[i] = b[i - 1];
        a[i] = a[i - 1] + 1;
      } else {
        bb++;
        a[i] = a[i - 1];
        b[i] = b[i - 1] + 1;
      }
    }
    int flag = 1;
    if (aa == 0 || bb == 0) {
      printf("-1 -1\n");
      continue;
    } else {
      for (int i = 1; i <= n; i++) {
        if (flag == 1)
          for (int j = n; j >= i; j--) {
            if (a[j] - a[i - 1] == b[j] - b[i - 1]) {
              printf("%d %d\n", i, j);
              flag = 0;
              break;
            }
          }
        else
          break;
      }
    }
  }
  return 0;
}
