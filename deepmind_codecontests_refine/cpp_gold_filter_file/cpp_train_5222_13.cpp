#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int H[1005];
int main() {
  int n, m, h;
  int l, r, x;
  int i, j;
  scanf("%d%d%d", &n, &h, &m);
  for (i = 1; i <= n; i++) H[i] = h;
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &l, &r, &x);
    for (j = l; j <= r; j++) H[j] = min(H[j], x);
  }
  int ans = 0;
  for (i = 1; i <= n; i++) ans += H[i] * H[i];
  printf("%d", ans);
  return 0;
}
