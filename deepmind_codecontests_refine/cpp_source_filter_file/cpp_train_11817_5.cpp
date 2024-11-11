#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long int v[4002];
  long long int d[4002];
  long long int p[4002];
  int mark[4002];
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", v + i, d + i, p + i);
    mark[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (mark[i]) {
      ++ans;
      mark[i] = 0;
      int cur = v[i];
      for (int j = i + 1; j <= n; ++j) {
        if (mark[j] == 1) {
          p[j] -= cur;
          cur = (cur - 1 > 0) ? cur - 1 : 0;
        }
      }
    }
    for (int j = i + 1; j <= n; ++j) {
      if (p[j] < 0 && mark[j] == 1) {
        mark[j] = 0;
        for (int k = j + 1; k <= n; ++k) {
          p[k] -= d[j];
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    if (p[i] >= 0) printf("%d ", i);
  }
  printf("\n");
}
