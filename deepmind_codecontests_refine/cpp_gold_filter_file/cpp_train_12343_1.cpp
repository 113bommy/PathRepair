#include <bits/stdc++.h>
using namespace std;
map<int, int> sls;
const int maxlen = 1000000;
void init() {
  sls.clear();
  for (int i = 1; i <= maxlen; i++) {
    if (1ll * i * (i - 1) / 2 > 1000000000) break;
    sls[i * (i - 1) / 2] = i;
  }
}
int main() {
  init();
  int a00, a01, a10, a11;
  while (~scanf("%d%d%d%d", &a00, &a01, &a10, &a11)) {
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0)
      printf("0\n");
    else if (a00 == 0 && a01 == 0 && a10 == 0) {
      if (!sls.count(a11))
        printf("Impossible\n");
      else {
        int n = sls[a11];
        for (int i = 1; i <= n; i++) printf("1");
        printf("\n");
      }
    } else if (a01 == 0 && a10 == 0 && a11 == 0) {
      if (!sls.count(a00))
        printf("Impossible\n");
      else {
        int m = sls[a00];
        for (int i = 1; i <= m; i++) printf("0");
        printf("\n");
      }
    } else {
      int n = sls[a11], m = sls[a00];
      if (n + m > 1000000 || 1ll * n * m != a01 + a10)
        printf("Impossible\n");
      else {
        int k = a10 / m;
        int pre = m - (a10 - m * k);
        for (int i = 1; i <= k; i++) printf("1");
        for (int i = 1; i <= pre; i++) printf("0");
        if (pre != m) printf("1");
        for (int i = pre + 1; i <= m; i++) printf("0");
        for (int i = k + 2; i <= n; i++) printf("1");
        if (pre == m && n > k) printf("1");
        printf("\n");
      }
    }
  }
  return 0;
}
