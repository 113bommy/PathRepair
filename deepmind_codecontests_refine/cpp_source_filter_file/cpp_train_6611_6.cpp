#include <bits/stdc++.h>
using namespace std;
const int M = 100010;
int a[M + 10], b[M + 10];
int ans[M + 10];
int sum[M + 10];
int tmp[M + 10];
int main() {
  int n, m, x;
  while (~scanf("%d%d", &n, &m)) {
    memset(tmp, 0, sizeof(0));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      sum[a[i]]++;
      tmp[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    int type = 1;
    for (int i = 1; i <= m; i++) {
      if (sum[b[i]] == 0) {
        type = 0;
        break;
      }
      if (sum[i] > 1) {
        type = 2;
        continue;
      }
      ans[i] = tmp[i];
    }
    if (type == 1) {
      puts("Possible");
      for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
      puts("");
    } else if (type == 0) {
      puts("Impossible");
    } else
      puts("Ambiguity");
  }
  return 0;
}
