#include <bits/stdc++.h>
using namespace std;
int ololo[5000][3], n, solved[3], canHack[3], score[3], willHack[3], bestPlace,
    dp[2][90][90][90], ci, li;
int submissionScore(int sc, int tm) {
  if (tm == 0) return 0;
  return sc * (250 - abs(tm)) / 250;
}
int calcScore(int p) {
  int sum = 0;
  for (int i = 0; i < 3; i++) sum += submissionScore(score[i], ololo[p][i]);
  return sum;
}
int countHacks(int p) {
  int cnt = 0;
  for (int i = 0; i < 3; i++) cnt += ololo[p][i] < 0;
  return cnt;
}
int solve() {
  memset(dp, 0, sizeof dp);
  int myScore = 0;
  for (int i = 0; i < 3; i++)
    myScore += 100 * willHack[i] + submissionScore(score[i], ololo[0][i]);
  ci = 0;
  li = 1;
  for (int p = 1; p < n; p++)
    if (countHacks(p) > 0 && calcScore(p) > myScore) {
      ci ^= 1;
      li ^= 1;
      for (int i = 0; i <= willHack[0]; i++)
        for (int j = 0; j <= willHack[1]; j++)
          for (int k = 0; k <= willHack[2]; k++)
            dp[ci][i][j][k] = dp[li][i][j][k];
      for (int ii = 0; ii < 2; ii++)
        for (int jj = 0; jj < 2; jj++)
          for (int kk = 0; kk < 2; kk++) {
            if (ii == 1 && ololo[p][0] >= 0) continue;
            if (jj == 1 && ololo[p][1] >= 0) continue;
            if (kk == 1 && ololo[p][2] >= 0) continue;
            int s = submissionScore(score[0], ololo[p][0]) * (ii ^ 1) +
                    submissionScore(score[1], ololo[p][1]) * (jj ^ 1) +
                    submissionScore(score[2], ololo[p][2]) * (kk ^ 1);
            if (s > myScore) continue;
            for (int i = ii; i <= willHack[0]; i++)
              for (int j = jj; j <= willHack[1]; j++)
                for (int k = kk; k <= willHack[2]; k++)
                  dp[ci][i][j][k] =
                      max(dp[ci][i][j][k], dp[li][i - ii][j - jj][k - kk] + 1);
          }
    }
  int res = 1 - dp[ci][willHack[0]][willHack[1]][willHack[2]];
  for (int p = 1; p < n; p++)
    if (calcScore(p) > myScore) res++;
  return res;
}
void brute(int p) {
  if (p == 3) {
    int res = solve();
    bestPlace = min(bestPlace, res);
    return;
  }
  for (int i = 0; i < 6; i++) {
    int mn = i == 5 ? 0 : (n >> (i + 1)) + 1;
    int mx = (n >> i);
    if (solved[p] >= mn && solved[p] - canHack[p] <= mx) {
      score[p] = 500 * (i + 1);
      willHack[p] = min(canHack[p], solved[p] - mn);
      brute(p + 1);
    }
  }
}
int main() {
  memset(solved, 0, sizeof solved);
  memset(canHack, 0, sizeof canHack);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++) {
      scanf("%d", &ololo[i][j]);
      solved[j] += ololo[i][j] != 0;
      canHack[j] += ololo[i][j] < 0;
    }
  if (canHack[0] + canHack[1] + canHack[2] > 89) {
    printf("1\n");
    return 0;
  }
  bestPlace = n;
  brute(0);
  printf("%d\n", bestPlace);
  return 0;
}
