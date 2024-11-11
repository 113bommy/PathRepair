#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int a[maxn][32];
int l[maxn], r[maxn], q[maxn];
int cnt[maxn][32];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &l[i], &r[i], &q[i]);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 30; ++j) {
      if (q[i] & (1 << j)) {
        ++a[l[i]][j];
        --a[r[i] + 1][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 30; ++j) {
      a[i][j] += a[i - 1][j];
      cnt[i][j] = cnt[i - 1][j] + (a[i][j] == 0);
    }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 30; ++j) {
      if ((!(q[i] & (1 << j))) && (cnt[r[i]][j] - cnt[l[i] - 1][j] == 0)) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) {
    int tmp = 0;
    for (int j = 0; j < 30; ++j) {
      if (a[i][j]) {
        tmp |= (1 << j);
      }
    }
    printf("%d", tmp);
    putchar(i == n ? '\n' : ' ');
  }
}
