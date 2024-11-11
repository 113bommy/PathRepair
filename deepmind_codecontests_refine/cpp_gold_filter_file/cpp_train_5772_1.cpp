#include <bits/stdc++.h>
using namespace std;
const int N = 20004;
int a[N][12], cnt[12], ans[N];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    cnt[y - 1]++;
    ans[x - 1]--;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j][i]) ans[j] += cnt[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }
}
