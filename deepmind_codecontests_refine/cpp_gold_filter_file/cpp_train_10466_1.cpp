#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int solTimes[n][3];
  bool canHack[n][3];
  int numSol[3];
  int canHackCount[3];
  int totalCanHack = 0;
  memset(numSol, 0, sizeof numSol);
  memset(canHackCount, 0, sizeof canHackCount);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> solTimes[i][j];
      if (solTimes[i][j] < 0) {
        solTimes[i][j] *= -1;
        canHack[i][j] = true;
        canHackCount[j]++;
        totalCanHack++;
      } else {
        canHack[i][j] = false;
      }
      if (solTimes[i][j] != 0) {
        numSol[j]++;
      }
    }
  }
  int maxSol[7];
  int c = n;
  maxSol[0] = c;
  while (n < 2 * c && 2 * c <= 2 * n) c--;
  maxSol[1] = c;
  while (n < 4 * c && 4 * c <= 2 * n) c--;
  maxSol[2] = c;
  while (n < 8 * c && 8 * c <= 2 * n) c--;
  maxSol[3] = c;
  while (n < 16 * c && 16 * c <= 2 * n) c--;
  maxSol[4] = c;
  while (n < 32 * c && 32 * c <= 2 * n) c--;
  maxSol[5] = c;
  maxSol[6] = -1;
  int bestAns = n;
  if (totalCanHack > 90) {
    bestAns = 1;
  } else {
    int currMaxScores[3];
    int numToHack[3];
    for (int i1 = 0; i1 < 6; i1++) {
      if (numSol[0] <= maxSol[i1 + 1]) continue;
      currMaxScores[0] = 500 + i1 * 500;
      numToHack[0] = min(canHackCount[0], numSol[0] - maxSol[i1 + 1] - 1);
      if (numSol[0] - numToHack[0] > maxSol[i1]) continue;
      for (int i2 = 0; i2 < 6; i2++) {
        if (numSol[1] <= maxSol[i2 + 1]) continue;
        currMaxScores[1] = 500 + i2 * 500;
        numToHack[1] = min(canHackCount[1], numSol[1] - maxSol[i2 + 1] - 1);
        if (numSol[1] - numToHack[1] > maxSol[i2]) continue;
        for (int i3 = 0; i3 < 6; i3++) {
          if (numSol[2] <= maxSol[i3 + 1]) continue;
          currMaxScores[2] = 500 + i3 * 500;
          numToHack[2] = min(canHackCount[2], numSol[2] - maxSol[i3 + 1] - 1);
          if (numSol[2] - numToHack[2] > maxSol[i3]) continue;
          vector<pair<int, int> > scores;
          for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = 0; j < 3; j++) {
              if (solTimes[i][j] > 0) {
                score -= currMaxScores[j] * (250 - solTimes[i][j]) / 250;
              }
            }
            if (i == 0)
              score -= (numToHack[0] + numToHack[1] + numToHack[2]) * 100;
            scores.push_back(pair<int, int>(score, i));
          }
          int ourScore = -scores[0].first;
          sort(scores.begin(), scores.end());
          if (scores[0].second == 0) {
            bestAns = 1;
            break;
          }
          int z = 0;
          while (scores[z].second != 0) z++;
          int reducedNumToHack[3];
          for (int j = 0; j < 3; j++) reducedNumToHack[j] = 0;
          for (int i = 0; i < z; i++) {
            for (int j = 0; j < 3; j++) {
              if (canHack[scores[i].second][j]) reducedNumToHack[j]++;
            }
          }
          for (int j = 0; j < 3; j++)
            reducedNumToHack[j] = min(reducedNumToHack[j], numToHack[j]);
          int dp[z][reducedNumToHack[0] + 1][reducedNumToHack[1] + 1]
                [reducedNumToHack[2] + 1];
          memset(dp, 0, sizeof dp);
          for (int pp = 0; pp < z; pp++) {
            int p = scores[pp].second;
            for (int k1 = 0; k1 <= reducedNumToHack[0]; k1++) {
              for (int k2 = 0; k2 <= reducedNumToHack[1]; k2++) {
                for (int k3 = 0; k3 <= reducedNumToHack[2]; k3++) {
                  int k[3];
                  k[0] = k1;
                  k[1] = k2;
                  k[2] = k3;
                  for (int hackBits = 0; hackBits < (1 << 3); hackBits++) {
                    int hacks[3];
                    for (int j = 0; j < 3; j++) {
                      hacks[j] = ((hackBits & (1 << j)) > 0) ? 1 : 0;
                    }
                    bool hackable = true;
                    for (int j = 0; j < 3; j++) {
                      if (hacks[j] > 0 && (k[j] == 0 || !canHack[p][j])) {
                        hackable = false;
                        break;
                      }
                    }
                    if (!hackable) continue;
                    int hackedScore = 0;
                    for (int j = 0; j < 3; j++) {
                      if (solTimes[p][j] > 0 && hacks[j] == 0) {
                        hackedScore +=
                            currMaxScores[j] * (250 - solTimes[p][j]) / 250;
                      }
                    }
                    int res = 0;
                    if (pp > 0)
                      res = dp[pp - 1][k[0] - hacks[0]][k[1] - hacks[1]]
                              [k[2] - hacks[2]];
                    if (hackedScore <= ourScore) res++;
                    dp[pp][k[0]][k[1]][k[2]] =
                        max(dp[pp][k[0]][k[1]][k[2]], res);
                  }
                }
              }
            }
          }
          bestAns =
              min(bestAns, z + 1 -
                               dp[z - 1][reducedNumToHack[0]]
                                 [reducedNumToHack[1]][reducedNumToHack[2]]);
        }
      }
    }
  }
  cout << bestAns << endl;
}
