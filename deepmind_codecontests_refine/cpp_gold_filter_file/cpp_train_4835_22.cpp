#include <bits/stdc++.h>
using namespace std;
int a[110][110], bin[20];
int m, n, k;
int main() {
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  int ans = k + 1;
  if (n <= 10) {
    while (!bin[0]) {
      int cnt = 0;
      for (int i = 1; i <= m; i++) {
        int diff = 0;
        for (int j = 1; j <= n; j++) diff += abs(a[i][j] - bin[j]);
        cnt += min(diff, n - diff);
      }
      ans = min(ans, cnt);
      int k = n;
      while (bin[k]) bin[k] = 0, k--;
      bin[k]++;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++)
        if (i != j) {
          int diff = 0;
          for (int k = 1; k <= m; k++) diff += abs(a[k][i] - a[k][j]);
          cnt += min(diff, m - diff);
        }
      ans = min(ans, cnt);
    }
  }
  if (ans == k + 1) ans = -1;
  printf("%d\n", ans);
  return 0;
}
