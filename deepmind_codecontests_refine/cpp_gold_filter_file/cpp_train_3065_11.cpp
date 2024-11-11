#include <bits/stdc++.h>
using namespace std;
int N, M, s, e;
int Sa[100010], Sb[100010];
int F[310][100010];
vector<int> P[100010];
int main() {
  scanf("%d%d%d%d", &N, &M, &s, &e);
  for (int i = 1; i <= N; i++) scanf("%d", &Sa[i]);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &Sb[i]);
    P[Sb[i]].push_back(i);
  }
  for (int i = 0; i <= 100010; i++) P[i].push_back(0x3f3f3f3f);
  memset(F, 0x3f, sizeof(F));
  memset(F[0], 0, sizeof(F[0]));
  int ans = 0;
  for (int i = 1; i <= s / e; i++)
    for (int j = 1; j <= N; j++)
      if (F[i - 1][j - 1] < 0x3f3f3f3f) {
        F[i][j] = F[i][j - 1];
        int tmp =
            *lower_bound(P[Sa[j]].begin(), P[Sa[j]].end(), F[i - 1][j - 1] + 1);
        F[i][j] = min(F[i][j], tmp);
        if (F[i][j] + j + i * e <= s) ans = max(ans, i);
      }
  printf("%d\n", ans);
  return 0;
}
