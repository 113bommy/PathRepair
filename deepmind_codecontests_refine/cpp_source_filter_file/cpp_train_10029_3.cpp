#include <bits/stdc++.h>
using namespace std;
int N, len, M, xc, yc, cc, L;
char st[1000005], s[2005];
string sc[2005];
vector<int> g[2005][27];
int sum[2005][26], a[2005];
pair<int, int> f[2005][2005];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%s", st);
    len = strlen(st);
    for (int j = 0; j < len; j++) sc[i] += st[j];
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= 26; j++) {
      for (int k = 0; k <= sc[i].size(); k++) g[i][j].push_back(-1);
      for (int k = sc[i].size() - 1; k >= 0; k--)
        if (sc[i][k] - 96 == j)
          g[i][j][k] = k;
        else
          g[i][j][k] = g[i][j][k + 1];
    }
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) scanf("%d", &a[i]);
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= 26; j++)
      if (g[a[i]][j][0] != -1)
        sum[i][j] = sum[i - 1][j] + 1;
      else
        sum[i][j] = sum[i - 1][j];
  scanf("%s", s + 1);
  L = strlen(s + 1);
  for (int i = 0; i <= L; i++)
    for (int j = 0; j <= L; j++) f[i][j] = make_pair(2147483647, 2147483647);
  f[0][0] = make_pair(1, 0);
  for (int i = 0; i < L; i++)
    for (int j = 0; j <= L; j++)
      if (f[i][j].first != 2147483647) {
        cc = s[i + 1] - 96;
        f[i + 1][j] = min(f[i + 1][j], f[i][j]);
        xc = f[i][j].first, yc = f[i][j].second;
        if (xc > M) continue;
        if (g[a[xc]][cc][yc] != -1) {
          yc = g[a[xc]][cc][yc];
          ++yc;
          if (yc >= sc[a[xc]].size()) ++xc, yc = 0;
          f[i + 1][j + 1] = min(f[i + 1][j + 1], make_pair(xc, yc));
        } else {
          int left = xc + 1, right = N, mid;
          while (left <= right) {
            mid = (left + right) / 2;
            if (sum[mid][cc] - sum[xc][cc] > 0)
              right = mid - 1;
            else
              left = mid + 1;
          }
          if (left <= N) {
            xc = left;
            yc = g[a[xc]][cc][0];
            ++yc;
            if (yc >= sc[a[xc]].size()) ++xc, yc = 0;
            f[i + 1][j + 1] = min(f[i + 1][j + 1], make_pair(xc, yc));
          }
        }
      }
  for (int i = L; i >= 0; i--)
    if (f[L][i].first != 2147483647) {
      printf("%d\n", i);
      break;
    }
  return 0;
}
