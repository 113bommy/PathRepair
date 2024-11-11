#include <bits/stdc++.h>
using namespace std;
int n, t;
int a[3][105];
int v[105];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[0][i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[1][i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[2][i]);
    v[1] = a[0][1];
    for (int i = 2; i <= n; i++) {
      int now = i - 1;
      int o = 0;
      for (int j = 1; j <= 3; j++)
        if (a[j][i] != v[now] && (i < n || a[j][i] != v[1])) {
          o = a[j][i];
          break;
        }
      v[i] = o;
    }
    for (int i = 1; i <= n; i++) printf("%d ", v[i]);
    puts("");
  }
  return 0;
}
