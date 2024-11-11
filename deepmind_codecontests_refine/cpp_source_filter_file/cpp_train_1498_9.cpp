#include <bits/stdc++.h>
using namespace std;
struct problem {
  int score1, score2;
  int time1, time2;
  double fail;
  long long expscore1, expscore2;
  double ratio;
};
int N, T;
problem P[1010];
long long dpscore[1010][1600];
double dppenal[1010][1600];
void update(int n, int t, long long score, double penal) {
  if (n <= N && t <= T &&
      (score > dpscore[n][t] ||
       (score == dpscore[n][t] && penal < dppenal[n][t]))) {
    dpscore[n][t] = score;
    dppenal[n][t] = penal;
  }
}
int main() {
  int i, j;
  cin >> N >> T;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    cin >> P[i].score1 >> P[i].score2 >> P[i].time1 >> P[i].time2 >> P[i].fail;
    P[i].expscore1 = (long long)P[i].score1 * (long long)1000000;
    int tmp = (floor)(P[i].fail * 1000000);
    P[i].expscore2 = (long long)P[i].score2 * (long long)(1000000 - tmp);
    P[i].ratio =
        ((tmp == 1000000) ? (1.0E+18)
                          : (P[i].time2 * P[i].fail / (1.0 - P[i].fail)));
  }
  for ((i) = 0; (i) < (int)(N + 5); (i)++)
    for ((j) = 0; (j) < (int)(N - 1); (j)++)
      if (P[j].ratio > P[j + 1].ratio) swap(P[j], P[j + 1]);
  for ((i) = 0; (i) < (int)(N + 1); (i)++)
    for ((j) = 0; (j) < (int)(T + 1); (j)++) dpscore[i][j] = -1;
  dpscore[0][0] = 0;
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(T + 1); (j)++)
      if (dpscore[i][j] != -1) {
        long long score = dpscore[i][j];
        double penal = dppenal[i][j];
        update(i + 1, j, score, penal);
        update(i + 1, j + P[i].time1, score + P[i].expscore1,
               penal + P[i].time1);
        double fail_penalty = penal + P[i].time1;
        double ac_penalty = j + P[i].time1 + P[i].time2;
        update(i + 1, j + P[i].time1 + P[i].time2,
               score + P[i].expscore1 + P[i].expscore2,
               fail_penalty * P[i].fail + ac_penalty * (1.0 - P[i].fail));
      }
  long long score = 0;
  double penal = 0.0;
  for ((i) = 0; (i) < (int)(T + 1); (i)++) {
    long long score2 = dpscore[N][i];
    double penal2 = dppenal[N][i];
    if (score2 > score || (score2 == score && penal2 < penal)) {
      score = score2;
      penal = penal2;
    }
  }
  printf("%.12f %.12f\n", score / 1000000.0, penal);
  return 0;
}
