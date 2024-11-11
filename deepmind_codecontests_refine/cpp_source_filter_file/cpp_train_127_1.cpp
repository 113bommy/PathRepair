#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int sum[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(sum, 0, sizeof sum);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) sum[a[i]]++;
    bool flag = true;
    for (int i = 1; i <= m; i++) {
      if (sum[b[i]]) {
        puts("YES");
        flag = false;
        printf("%d\n", b[i]);
        break;
      }
    }
    if (flag) puts("NO");
  }
  return 0;
}
