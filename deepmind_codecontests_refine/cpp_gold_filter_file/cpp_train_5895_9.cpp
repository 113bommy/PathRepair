#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int t[200005];
int l[200005];
int r[200005];
int main() {
  int n, q, m;
  scanf("%d%d%d", &n, &q, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &t[i], &l[i], &r[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  for (int k = 1; k <= m; k++) {
    int pos = b[k];
    for (int i = q; i >= 1; i--) {
      if (pos < l[i] || pos > r[i]) {
        continue;
      }
      if (t[i] == 1) {
        if (pos > l[i])
          pos--;
        else
          pos = r[i];
      } else {
        pos = l[i] + r[i] - pos;
      }
    }
    printf("%d ", a[pos]);
  }
  printf("\n");
  return 0;
}
