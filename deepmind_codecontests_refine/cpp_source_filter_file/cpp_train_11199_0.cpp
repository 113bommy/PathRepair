#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
long long cnt[26][maxn][maxn];
long long a[maxn][maxn], f[maxn][maxn];
int x_1[300007], y_1[300007], x_2[300007], y_2[300007], c[300007];
int n, m, k;
long long get_ans(int xl, int yl, int xr, int yr, int ch) {
  long long s = 0;
  for (int q = 0; q < 26; ++q) {
    s += abs(q - ch) * (cnt[q][yr][xr] - cnt[q][yr][xl - 1] -
                        cnt[q][yl - 1][xr] + cnt[q][yl - 1][xl - 1]);
  }
  return f[n][m] - f[yr][xr] + f[yr][xl - 1] + f[yl - 1][xr] -
         f[yl - 1][xl - 1] + s;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    getchar();
    for (int j = 1; j <= m; ++j) a[i][j] = getchar() - 'a';
  }
  for (int i = 0; i < k; ++i) {
    char ch;
    scanf("%d %d %d %d %c", x_1 + i, y_1 + i, x_2 + i, y_2 + i, &ch);
    c[i] = ch - 'a';
    cnt[c[i]][y_1[i]][x_1[i]]++;
    cnt[c[i]][y_2[i] + 1][x_1[i]]--;
    cnt[c[i]][y_1[i]][x_2[i] + 1]--;
    cnt[c[i]][y_2[i] + 1][x_2[i] + 1]++;
  }
  for (int q = 0; q < 26; ++q)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cnt[q][i][j] +=
            cnt[q][i - 1][j] + cnt[q][i][j - 1] - cnt[q][i - 1][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int q = 0; q < 26; ++q) f[i][j] += abs(q - a[i][j]) * cnt[q][i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int s = 0;
      for (int q = 0; q < 26; ++q) s += cnt[q][i][j];
      cnt[a[i][j]][i][j] += k - s;
    }
  for (int q = 0; q < 26; ++q)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cnt[q][i][j] +=
            cnt[q][i - 1][j] + cnt[q][i][j - 1] - cnt[q][i - 1][j - 1];
  long long ans = 1e18;
  for (int i = 0; i < k; ++i)
    ans = min(ans, get_ans(x_1[i], y_1[i], x_2[i], y_2[i], c[i]));
  printf("%lld\n", ans);
  return 0;
}
