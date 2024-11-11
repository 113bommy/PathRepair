#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(15);
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    for (int j = 0; j < m; j++) scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      bool chk[MAXN] = {0};
      int num = k, tmp = 0;
      while (num > 0) {
        int idx = -1, profit = 0;
        for (int l = 0; l < m; l++) {
          if (!chk[l] && c[i][l] > 0 && b[j][l] - a[i][l] > profit) {
            idx = l;
            profit = b[j][l] - a[i][l];
          }
        }
        if (profit > 0) {
          chk[idx] = 1;
          tmp += min(num, c[i][idx]) * profit;
          num -= min(num, c[i][idx]);
        } else {
          break;
        }
      }
      ans = max(ans, tmp);
    }
  printf("%d", ans);
}
