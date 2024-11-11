#include <bits/stdc++.h>
using namespace std;
int v[6];
int main() {
  int n, i, j, x, m = 0;
  v[0] = -1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (j = 1; j <= m; j++)
      if (x == v[j]) break;
    if (j > m) {
      m++;
      v[m] = x;
      if (m >= 4) break;
    }
  }
  sort(v + 1, v + 3);
  if ((v[2] - v[1] == v[3] - v[2] || m < 3) && m < 4)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
