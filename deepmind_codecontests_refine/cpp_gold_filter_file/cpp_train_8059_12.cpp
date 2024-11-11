#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char s[100005];
const int N = 1e5 + 5;
int sum[N], cnt[11][N], a[N];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0', sum[i] = sum[i - 1] + a[i];
  for (int i = 0; i < k; i++) {
    for (int j = 0, p = i; p <= n; p += k, j++) {
      cnt[i][j] = cnt[i][j - 1] + a[p];
    }
  }
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    int tmp = cnt[y % k][y / k] - cnt[y % k][(x - 1) / k];
    int ans = sum[y] - sum[x - 1] - tmp + (y - x + 1) / k - tmp;
    printf("%d\n", ans);
  }
  return 0;
}
