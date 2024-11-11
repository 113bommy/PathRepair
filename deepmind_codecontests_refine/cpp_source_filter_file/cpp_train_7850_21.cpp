#include <bits/stdc++.h>
using namespace std;
int K, noww, aa, bb, prea, preb;
bool flag[410][410];
inline void solve() {
  scanf("%d", &K);
  noww = -1;
  prea = preb = K;
  while (1) {
    aa = prea / 2;
    bb = preb - preb / 2;
    if (noww == -1) {
      flag[3][1] = flag[5][1] = 1;
    } else {
      if (aa + aa == prea)
        flag[noww][noww + 4] = flag[noww][noww + 5] = flag[noww + 1][noww + 4] =
            flag[noww + 1][noww + 5] = 1;
      else if (aa + bb == prea) {
        flag[noww][noww + 4] = flag[noww][noww + 6] = flag[noww + 1][noww + 4] =
            flag[noww + 1][noww + 6] = 1;
      } else {
        flag[noww][noww + 6] = flag[noww][noww + 7] = flag[noww + 1][noww + 6] =
            flag[noww + 1][noww + 7] = 1;
      }
      if (aa + aa == prea)
        flag[noww + 2][noww + 4] = flag[noww + 2][noww + 5] =
            flag[noww + 3][noww + 4] = flag[noww + 3][noww + 5] = 1;
      else if (aa + bb == prea) {
        flag[noww + 2][noww + 4] = flag[noww + 2][noww + 6] =
            flag[noww + 3][noww + 4] = flag[noww + 3][noww + 6] = 1;
      } else {
        flag[noww + 2][noww + 6] = flag[noww + 2][noww + 7] =
            flag[noww + 3][noww + 6] = flag[noww + 3][noww + 7] = 1;
      }
    }
    prea = aa;
    preb = bb;
    noww += 4;
    if ((aa == 0 && bb == 1) || (aa == 1 && bb == 1)) break;
  }
  for (int i = noww; i <= noww + 1; i++)
    if (aa == 1) flag[2][i] = 1;
  for (int i = noww + 2; i <= noww + 3; i++)
    if (bb == 1) flag[2][i] = 1;
  printf("%d\n", noww + 3);
  for (int i = 1; i <= noww + 3; i++) {
    for (int j = 1; j <= noww + 3; j++) {
      if (flag[i][j] || flag[j][i])
        printf("Y");
      else
        printf("N");
    }
    printf("\n");
  }
}
int main() {
  solve();
  return 0;
}
