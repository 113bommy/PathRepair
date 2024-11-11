#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 10;
int n, dis[N][M], dch[M][M], mask[N], cnt[M][30 * M];
vector<int> p[M];
char a[N];
long long mxans = 0, mxnum = 0;
void upd(long long ans, long long num) {
  if (mxans < ans) mxans = ans, mxnum = 0;
  if (mxans == ans) mxnum += num;
}
void work_dis(int A) {
  int tmp;
  dis[1][A] = tmp = (a[1] == A + 96) ? 0 : 0x3f3f3f3f;
  for (int i = 2; i <= n; i++) {
    if (a[i] == A + 96)
      tmp = 0;
    else
      tmp = (tmp == 0x3f3f3f3f) ? tmp : tmp + 1;
    dis[i][A] = tmp;
  }
  dis[n][A] = min(dis[n][A], tmp = (a[n] == A + 96) ? 0 : 0x3f3f3f3f);
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == A + 96)
      tmp = 0;
    else
      tmp = (tmp == 0x3f3f3f3f) ? tmp : tmp + 1;
    dis[i][A] = min(dis[i][A], tmp);
  }
}
int main() {
  scanf("%d%s", &n, a + 1);
  for (int i = 1; i <= n; i++) p[a[i] - 96].push_back(i);
  for (int i = 1; i <= 8; i++) work_dis(i);
  memset(dch, 0x3f, sizeof(dch));
  for (int i = 1; i <= 8; i++) dch[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++)
        dch[i][j] = min(dch[i][j], dis[k][i] + dis[k][j]);
  for (int k = 1; k <= 8; k++)
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++)
        dch[i][j] = min(dch[i][j], dch[i][k] + dch[k][j] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 8; j++)
      for (int k = 1; k <= 8; k++)
        dis[i][k] = min(dis[i][k], dis[i][j] + dch[j][k] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 8; j++)
      mask[i] |= (dis[i][j] - dch[a[i] - 96][j]) << (j - 1);
  for (int r = 1; r <= n; r++)
    for (int l = max(1, r - 15), mindis; l < r; l++) {
      mindis = r - l;
      for (int i = 1; i <= 8; i++)
        mindis = min(mindis, dis[l][i] + dis[r][i] + 1);
      upd(mindis, 1);
    }
  for (int i = 17, j = 1; i <= n; i++, j++) {
    cnt[a[j]][mask[j]]++;
    for (int ch = 1; ch <= 8; ch++)
      for (int st = 0; st < 256; st++)
        if (cnt[ch][st]) {
          int mindis = 0x3f3f3f3f;
          for (int k = 1; k <= 8; k++)
            mindis =
                min(mindis, dch[ch][k] + dis[i][k] + ((st >> (k - 1)) & 1) + 1);
          upd(mindis, cnt[ch][st]);
        }
  }
  printf("%lld %lld\n", mxans, mxnum);
}
