#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
int a[N][N], n, m, k, ans = INF;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  if (n <= k) {
    for (int t = 0; t < (1 << n); t++) {
      int tmp = 0;
      for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
          if (a[i][j] == (t >> j & 1)) cnt++;
        tmp += min(cnt, n - cnt);
      }
      ans = min(ans, tmp);
    }
  } else {
    for (int t = 0; t < n; t++) {
      int tmp = 0;
      for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++)
          if (a[i][j] == a[t][j]) cnt++;
        tmp += min(cnt, m - cnt);
      }
      ans = min(ans, tmp);
    }
  }
  if (ans <= k)
    printf("%d\n", ans);
  else
    puts("-1");
}
