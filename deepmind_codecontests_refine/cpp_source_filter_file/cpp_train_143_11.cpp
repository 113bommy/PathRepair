#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int INF = 1e9 + 7;
int l[maxn], r[maxn], cmd[maxn], val[maxn], limit[maxn], temp[maxn];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) limit[i] = INF;
    for (int i = 1; i <= m; i++)
      scanf("%d%d%d%d", &cmd[i], &l[i], &r[i], &val[i]);
    for (int i = m; i >= 1; i--) {
      if (cmd[i] == 1) {
        for (int j = l[i]; j <= r[i]; j++)
          if (limit[j] != INF) {
            limit[j] -= val[i];
          }
      } else {
        for (int j = l[i]; j <= r[i]; j++) {
          limit[j] = min(limit[j], val[i]);
        }
      }
    }
    for (int i = 1; i <= n; i++) temp[i] = limit[i];
    int flag = 0;
    for (int i = 1; i <= m; i++) {
      if (cmd[i] == 1) {
        for (int j = l[i]; j <= r[i]; j++) temp[j] += val[i];
      } else {
        int max1 = -INF;
        for (int j = l[i]; j <= r[i]; j++) {
          max1 = max(max1, temp[j]);
        }
        if (max1 != val[i]) {
          flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      printf("YES\n");
      for (int i = 1; i <= n; i++) printf("%d ", limit[i]);
      printf("\n");
    } else
      printf("NO\n");
  }
  return 0;
}
