#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int now[N][N];
long long sum[N][N], f[N][N][26];
char s[N][N];
struct query {
  int a, b, c, d;
  char str;
} q[M];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf(" %s", s[i] + 1);
  for (int i = 1; i <= k; i++)
    scanf("%d %d %d %d %c", &q[i].a, &q[i].b, &q[i].c, &q[i].d, &q[i].str);
  for (int i = 1; i <= k; i++) {
    int id = q[i].str - 'a', a = q[i].a, b = q[i].b, c = q[i].c, d = q[i].d;
    f[a][b][id]++;
    f[c + 1][b][id]--;
    f[a][d + 1][id]--;
    f[c + 1][d + 1][id]++;
  }
  for (int p = 0; p < 26; p++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j][p] += f[i][j - 1][p] + f[i - 1][j][p] - f[i - 1][j - 1][p];
        now[i][j] += f[i][j][p];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j][s[i][j] - 'a'] += k - now[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int p = 0; p < 26; p++) {
        sum[i][j] += f[i][j][p] * abs(s[i][j] - 'a' - p);
      }
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int p = 0; p < 26; p++) {
        f[i][j][p] += f[i - 1][j][p] + f[i][j - 1][p] - f[i - 1][j - 1][p];
      }
    }
  }
  long long ans = 1e18;
  for (int i = 1; i <= k; i++) {
    int id = q[i].str - 'a', a = q[i].a, b = q[i].b, c = q[i].c, d = q[i].d;
    long long x = 0;
    long long res =
        sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
    x += sum[n][m] - res;
    for (int j = 0; j < 26; j++) {
      int num =
          f[c][d][j] - f[c][b - 1][j] - f[a - 1][d][j] + f[a - 1][b - 1][j];
      x += num * abs(id - j);
    }
    ans = min(ans, x);
  }
  cout << ans << endl;
  return 0;
}
