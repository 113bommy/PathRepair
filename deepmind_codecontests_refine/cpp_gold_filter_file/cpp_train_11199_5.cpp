#include <bits/stdc++.h>
using namespace std;
int N, M, K;
char a[1005][1005];
long long cnt[26][1005][1005];
long long cst[1005][1005];
pair<int, pair<pair<int, int>, pair<int, int> > > qry[300005];
long long scst[1005][1005];
long long sless[1005][1005], cless[1005][1005], ssless[1005][1005],
    scless[1005][1005];
long long smore[1005][1005], cmore[1005][1005], ssmore[1005][1005],
    scmore[1005][1005];
int main() {
  scanf("%d%d%d\n", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    gets(a[i] + 1);
    for (int j = 1; j <= M; j++) a[i][j] -= 'a';
  }
  for (int i = 1; i <= K; i++) {
    int x1, y1, x2, y2;
    char ch;
    scanf("%d%d%d%d %c", &x1, &y1, &x2, &y2, &ch);
    ch -= 'a';
    qry[i] = {int(ch), {{x1, y1}, {x2, y2}}};
    cnt[ch][x1][y1]++;
    cnt[ch][x1][y2 + 1]--;
    cnt[ch][x2 + 1][y1]--;
    cnt[ch][x2 + 1][y2 + 1]++;
  }
  sort(qry + 1, qry + K + 1);
  for (int k = 0; k < 26; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        cnt[k][i][j] +=
            cnt[k][i - 1][j] + cnt[k][i][j - 1] - cnt[k][i - 1][j - 1];
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      long long tot = 0;
      for (int k = 0; k < 26; k++) tot += cnt[k][i][j];
      cnt[a[i][j]][i][j] += (K - tot);
    }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      for (int k = 0; k < 26; k++) cst[i][j] += cnt[k][i][j] * abs(k - a[i][j]);
      scst[i][j] =
          scst[i - 1][j] + scst[i][j - 1] - scst[i - 1][j - 1] + cst[i][j];
    }
  for (int k = 1; k < 26; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) {
        cmore[i][j] += cnt[k][i][j];
        smore[i][j] += cnt[k][i][j] * k;
        scmore[i][j] = scmore[i - 1][j] + scmore[i][j - 1] -
                       scmore[i - 1][j - 1] + cmore[i][j];
        ssmore[i][j] = ssmore[i - 1][j] + ssmore[i][j - 1] -
                       ssmore[i - 1][j - 1] + smore[i][j];
      }
  int ch = 0;
  long long ans = 1LL << 61;
  for (int i = 1; i <= K; i++) {
    int c = qry[i].first;
    int x1 = qry[i].second.first.first;
    int y1 = qry[i].second.first.second;
    int x2 = qry[i].second.second.first;
    int y2 = qry[i].second.second.second;
    while (ch < c) {
      ch++;
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
          cless[i][j] += cnt[ch - 1][i][j];
          sless[i][j] += cnt[ch - 1][i][j] * (ch - 1);
          scless[i][j] = scless[i - 1][j] + scless[i][j - 1] -
                         scless[i - 1][j - 1] + cless[i][j];
          ssless[i][j] = ssless[i - 1][j] + ssless[i][j - 1] -
                         ssless[i - 1][j - 1] + sless[i][j];
          cmore[i][j] -= cnt[ch][i][j];
          smore[i][j] -= cnt[ch][i][j] * ch;
          scmore[i][j] = scmore[i - 1][j] + scmore[i][j - 1] -
                         scmore[i - 1][j - 1] + cmore[i][j];
          ssmore[i][j] = ssmore[i - 1][j] + ssmore[i][j - 1] -
                         ssmore[i - 1][j - 1] + smore[i][j];
        }
    }
    long long cost1 = scst[N][M] - (scst[x2][y2] - scst[x2][y1 - 1] -
                                    scst[x1 - 1][y2] + scst[x1 - 1][y1 - 1]);
    long long cost2 = 1LL * c *
                          (scless[x2][y2] - scless[x2][y1 - 1] -
                           scless[x1 - 1][y2] + scless[x1 - 1][y1 - 1]) -
                      (ssless[x2][y2] - ssless[x1 - 1][y2] -
                       ssless[x2][y1 - 1] + ssless[x1 - 1][y1 - 1]);
    long long cost3 = (ssmore[x2][y2] - ssmore[x1 - 1][y2] -
                       ssmore[x2][y1 - 1] + ssmore[x1 - 1][y1 - 1]) -
                      1LL * c *
                          (scmore[x2][y2] - scmore[x2][y1 - 1] -
                           scmore[x1 - 1][y2] + scmore[x1 - 1][y1 - 1]);
    long long cost = cost1 + cost2 + cost3;
    ans = min(ans, cost);
  }
  printf("%I64d\n", ans);
  return 0;
}
