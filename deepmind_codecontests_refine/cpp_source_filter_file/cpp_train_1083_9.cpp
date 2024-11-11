#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2100, MMAX = 2100, SMAX = 101000, KMAX = 10, INF = ~0u >> 1;
int N, M, K, S, answer;
int note[NMAX][MMAX], line[KMAX][4], value[KMAX][KMAX], song[SMAX];
int main() {
  int i, j;
  scanf("%d %d %d %d", &N, &M, &K, &S);
  for (i = 1; i <= K; i += 1) {
    line[i][0] = line[i][1] = INF;
    line[i][2] = line[i][3] = -INF;
  }
  for (i = 1; i <= N; i += 1) {
    for (j = 1; j <= M; j += 1) {
      scanf("%d", &note[i][j]);
      line[note[i][j]][0] = min(line[note[i][j]][0], i + j);
      line[note[i][j]][3] = max(line[note[i][j]][3], i + j);
      line[note[i][j]][1] = min(line[note[i][j]][1], i - j);
      line[note[i][j]][2] = max(line[note[i][j]][2], i - j);
    }
  }
  for (i = 1; i <= K; i += 1) {
    for (j = i; j <= K; j += 1)
      value[i][j] =
          max(max(abs(line[i][0] - line[j][3]), abs(line[i][3] - line[j][0])),
              max(abs(line[i][1] - line[j][2]), abs(line[i][1] - line[j][2])));
  }
  for (i = 1; i <= S; i += 1) scanf("%d", &song[i]);
  for (i = 2; i <= S; i += 1)
    answer = max(answer,
                 value[min(song[i - 1], song[i])][max(song[i - 1], song[i])]);
  printf("%d\n", answer);
  exit(0);
}
