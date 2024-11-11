#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005], a1[1005][1005], a2[1005][1005];
int b[1005];
int mx1[1005], mx2[1005];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int nw;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[j] = a[i][j];
    }
    sort(b + 1, b + 1 + m);
    mx1[i] = unique(b + 1, b + m + 1) - b - 1;
    for (int j = 1; j <= m; ++j) {
      a1[i][j] = lower_bound(b + 1, b + mx1[i] + 1, a[i][j]) - b;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      b[j] = a[j][i];
    }
    sort(b + 1, b + 1 + n);
    mx2[i] = unique(b + 1, b + n + 1) - b - 1;
    for (int j = 1; j <= n; ++j) {
      a2[j][i] = lower_bound(b + 1, b + mx2[i] + 1, a[j][i]) - b;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d ", max(a1[i][j], a2[i][j]) +
                        max(mx1[i] - a1[i][j], mx2[i] - a2[i][j]));
    }
    puts("");
  }
}
int main() {
  init();
  return 0;
}
