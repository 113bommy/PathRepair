#include <bits/stdc++.h>
using namespace std;
int data1[1005], data2[1005];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    for (i = 1; i <= n; i++) scanf("%d", &data1[i]);
    for (i = 1; i <= n; i++) scanf("%d", &data2[i]);
    int j;
    int ans = 0;
    for (i = 1; i <= n; i++) {
      int flag = 0;
      for (j = 0; i + j <= n; j++) {
        int flag1 = 0, flag2 = 0;
        for (int k = i; k <= i + j; k++) {
          flag1 = flag1 | data1[k];
          flag2 = flag2 | data2[k];
        }
        if (flag1 + flag2 > ans) ans = flag1 + flag2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
