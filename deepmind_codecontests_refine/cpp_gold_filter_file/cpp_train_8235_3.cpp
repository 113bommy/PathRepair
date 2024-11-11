#include <bits/stdc++.h>
using namespace std;
struct MatchInfo {
  bool isCalc;
  bool bEnd;
  int nRes[2];
  int nMatches;
  int nMatchScore[5][2];
} stat[201][201][4][4];
void dp(int x, int y, int z, int u, int v) {
  if (x == 75 && y == 0 && u == 3) u = 3;
  MatchInfo *pMatch = &stat[x][y][u][v];
  if (pMatch->isCalc) return;
  if (z == 0) {
    return;
  }
  int nMaxScore = 5 == z ? 15 : 25;
  int bst = -100;
  int bst2 = -100;
  for (int nScore2 = 0; nScore2 < nMaxScore - 1; nScore2++) {
    int nScore1 = nMaxScore;
    if (x - nScore1 < 0) continue;
    if (y - nScore2 < 0) continue;
    if (u == 0) continue;
    dp(x - nScore1, y - nScore2, z - 1, u - 1, v);
    MatchInfo *pMatchC = &stat[x - nScore1][y - nScore2][u - 1][v];
    if (!pMatchC->bEnd) continue;
    if (max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) continue;
    int nDiff = pMatchC->nRes[0] - pMatchC->nRes[1] + 1;
    if (nDiff > bst) {
      bst = nDiff;
      memcpy(pMatch, pMatchC, sizeof(MatchInfo));
      pMatch->nMatchScore[z - 1][0] = nScore1;
      pMatch->nMatchScore[z - 1][1] = nScore2;
      pMatch->nRes[0]++;
    }
  }
  for (int nScore1 = 0; nScore1 < nMaxScore - 1; nScore1++) {
    int nScore2 = nMaxScore;
    if (x - nScore1 < 0) continue;
    if (y - nScore2 < 0) continue;
    if (v == 0) continue;
    dp(x - nScore1, y - nScore2, z - 1, u, v - 1);
    MatchInfo *pMatchC = &stat[x - nScore1][y - nScore2][u][v - 1];
    if (!pMatchC->bEnd) continue;
    if (max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) continue;
    int nDiff = pMatchC->nRes[0] - pMatchC->nRes[1] - 1;
    if (nDiff > bst) {
      bst = nDiff;
      memcpy(pMatch, pMatchC, sizeof(MatchInfo));
      pMatch->nMatchScore[z - 1][0] = nScore1;
      pMatch->nMatchScore[z - 1][1] = nScore2;
      pMatch->nRes[1]++;
    }
  }
  for (int nScore1 = nMaxScore - 1; nScore1 < 200; nScore1++) {
    int nScore2 = nScore1 + 2;
    if (x - nScore1 < 0) continue;
    if (y - nScore2 < 0) continue;
    if (v == 0) continue;
    dp(x - nScore1, y - nScore2, z - 1, u, v - 1);
    MatchInfo *pMatchC = &stat[x - nScore1][y - nScore2][u][v - 1];
    if (!pMatchC->bEnd) continue;
    if (max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) continue;
    int nDiff = pMatchC->nRes[0] - pMatchC->nRes[1] - 1;
    if (nDiff > bst) {
      bst = nDiff;
      memcpy(pMatch, pMatchC, sizeof(MatchInfo));
      pMatch->nMatchScore[z - 1][0] = nScore1;
      pMatch->nMatchScore[z - 1][1] = nScore2;
      pMatch->nRes[1]++;
    }
  }
  for (int nScore2 = nMaxScore - 1; nScore2 < 300; nScore2++) {
    int nScore1 = nScore2 + 2;
    if (x - nScore1 < 0) continue;
    if (y - nScore2 < 0) continue;
    if (u == 0) continue;
    dp(x - nScore1, y - nScore2, z - 1, u - 1, v);
    MatchInfo *pMatchC = &stat[x - nScore1][y - nScore2][u - 1][v];
    if (!pMatchC->bEnd) continue;
    if (max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) {
      pMatchC = &stat[x - nScore1][y - nScore2][z - 1][1];
      if (!pMatchC->bEnd) continue;
      if (max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) continue;
    }
    int nDiff = pMatchC->nRes[0] - pMatchC->nRes[1] + 1;
    if (nDiff > bst) {
      bst = nDiff;
      memcpy(pMatch, pMatchC, sizeof(MatchInfo));
      pMatch->nMatchScore[z - 1][0] = nScore1;
      pMatch->nMatchScore[z - 1][1] = nScore2;
      pMatch->nRes[0]++;
    }
  }
  if (x == 175 && y == 127 && z == 3) z = 3;
  if (bst > -99) pMatch->bEnd = true;
  pMatch->nMatches = z;
  pMatch->isCalc = 1;
}
int main() {
  int m;
  scanf("%i", &m);
  stat[0][0][0][0].isCalc = 1;
  stat[0][0][0][0].bEnd = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%i%i", &x, &y);
    int bst = -99;
    MatchInfo *pMatch = NULL;
    for (int j = 0; j <= 3; j++)
      for (int k = 0; k <= 3; k++) {
        if (j + k > 5) continue;
        dp(x, y, j + k, j, k);
        MatchInfo *pMatchC = &stat[x][y][j][k];
        if (pMatchC->bEnd && max(pMatchC->nRes[0], pMatchC->nRes[1]) == 3) {
          int nDiff = pMatchC->nRes[0] - pMatchC->nRes[1];
          if (nDiff > bst) {
            bst = nDiff;
            pMatch = pMatchC;
          }
        }
      }
    if (!pMatch)
      printf("Impossible\n");
    else {
      printf("%i:%i\n", pMatch->nRes[0], pMatch->nRes[1]);
      for (int j = 0; j < pMatch->nMatches; j++) {
        printf("%i:%i ", pMatch->nMatchScore[j][0], pMatch->nMatchScore[j][1]);
      }
      printf("\n");
    }
  }
}
