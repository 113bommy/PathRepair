#include <bits/stdc++.h>
using namespace std;
int p, q, l, r;
int v1[55], v2[55];
int t1[55], t2[55];
int main() {
  scanf("%d%d%d%d", &p, &q, &l, &r);
  for (int i = 0; i < p; i++) scanf("%d%d", &v1[i], &v2[i]);
  for (int i = 0; i < q; i++) scanf("%d%d", &t1[i], &t2[i]);
  int ans = 0;
  for (int i = l; i <= r; i++) {
    int f = 0;
    for (int j = 0; j < p; j++) {
      int a = v1[j];
      int b = v2[j];
      for (int k = 0; k < q; k++) {
        int c = t1[k] + i;
        int d = t2[k] + i;
        if ((a >= c && a <= d) || (b >= c && b <= d)) f = 1;
        if ((c >= a && c <= a) || (d >= a && d <= b)) f = 1;
      }
    }
    if (f) ans++;
  }
  printf("%d\n", ans);
}
