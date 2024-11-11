#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
int n;
int a[maxn][maxn];
int len[maxn], l[maxn];
int cnt[maxn], cc[maxn], ans[maxn];
bool flag[maxn][maxn], f[maxn][maxn];
bool solve(int x) {
  for (int i = 1; i <= n; i++) {
    if (f[i][x] == 1) {
      f[i][x] = 0;
      l[i]--;
      break;
    }
  }
  ans[1] = x;
  for (int t = 2; t <= n; t++) {
    bool jud = 0;
    for (int i = 1; i <= n; i++) {
      if (l[i] == 1) {
        jud = 1;
        for (int j = 1; j <= n; j++) {
          if (f[i][j]) {
            ans[t] = j;
            for (int k = 1; k <= n; k++) {
              if (f[k][j]) l[k]--;
              f[k][j] = 0;
            }
            break;
          }
        }
        break;
      }
    }
    if (!jud) return 0;
  }
  return 1;
}
int main() {
  int T;
  scanf("%d", &T);
  int cntk = 0;
  while (T--) {
    cntk++;
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    memset(flag, 0, sizeof(flag));
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n - 1; i++) {
      scanf("%d", &len[i]);
      for (int j = 1; j <= len[i]; j++) {
        scanf("%d", &a[i][j]);
        cnt[a[i][j]]++;
        flag[i][a[i][j]] = 1;
      }
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
      cc[i] = cnt[i];
      if (cnt[i] == 1) num++;
    }
    if (num == 2) {
      bool jud = 0;
      for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
          for (int j = 1; j <= n; j++) l[j] = len[j];
          for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) f[j][k] = flag[j][k];
          if (solve(i)) {
            jud = 1;
            break;
          }
        }
      }
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      printf("\n");
      continue;
    }
    for (int i = 1; i <= n - 1; i++) {
      int p = 0;
      for (int j = 1; j <= n; j++) {
        if (cnt[j] == 1) {
          if (p == 0)
            p = j;
          else {
            if (cc[p] < cc[j]) p = j;
          }
        }
      }
      for (int j = 1; j <= n; j++) {
        if (len[j] && flag[j][p] == 1) {
          for (int k = 1; k <= len[j]; k++) {
            cnt[a[j][k]]--;
            if (i == n - 1 && a[j][k] != p) ans[1] = a[j][k];
          }
          len[j] = 0;
        }
      }
      ans[n - i + 1] = p;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
