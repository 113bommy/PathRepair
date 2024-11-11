#include <bits/stdc++.h>
using namespace std;
int N, M, K;
const int KMax = 500005;
const int NMax = 505;
const long long INF = 1000000000LL * 500 * 500 + 5;
int X[KMax], Y[KMax], D[KMax], T[KMax], E[KMax];
long long DP[2][2][NMax][NMax];
vector<int> V[2][NMax][NMax];
long long AddEnergy[NMax][NMax], SubEnergy[2][NMax][NMax];
void Read() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= K; i++) {
    scanf("%d%d%d%d%d", &X[i], &Y[i], &D[i], &T[i], &E[i]);
  }
}
inline bool cmp(int a, int b) { return D[a] < D[b]; }
bool arrive(int x, int y, int ord, int t) {
  return x + y >= t + ord && (x + y - t) % 4 == ord;
}
void precalcAddEnergy() {
  for (int i = 1; i <= K; i++) {
    int x = X[i], y = Y[i], d = D[i], t = T[i], e = E[i];
    if (arrive(x, y, 0, t)) {
      AddEnergy[x][y] += e;
    }
    if (arrive(x + d, y - d, 1, t)) {
      AddEnergy[x + d][y - d] += e;
    }
    if (arrive(x + d, y, 2, t)) {
      AddEnergy[x + d][y] += e;
    }
    if (arrive(x, y + d, 3, t)) {
      AddEnergy[x][y + d] += e;
    }
    if (arrive(x, y, 0, t) && arrive(x, y + d, 3, t)) {
      SubEnergy[0][x][y + d] += e;
      V[0][x][y + d].push_back(i);
    }
    if (arrive(x + d, y, 2, t) && arrive(x + d, y - d, 1, t)) {
      V[0][x + d][y].push_back(i);
    }
    if (arrive(x, y, 0, t) && arrive(x + d, y, 2, t)) {
      V[1][x + d][y].push_back(i);
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      sort(V[0][i][j].begin(), V[0][i][j].end(), cmp);
      sort(V[1][i][j].begin(), V[1][i][j].end(), cmp);
    }
}
void Solve() {
  int ind = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++)
      for (int k = 0; k < max(N, M); k++) DP[0][i][j][k] = INF;
  }
  DP[0][0][0][0] = DP[0][1][0][0] = AddEnergy[0][0];
  for (int sum = 1; sum <= N + M - 2; sum++, ind ^= 1) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < N; j++)
        for (int k = 0; k < max(N, M); k++) DP[ind][i][j][k] = INF;
    for (int i = 0; i < 2; i++) {
      for (int j = max(0, sum - (M - 1)); j <= min(N - 1, sum); j++) {
        int x = j, y = sum - x;
        if (i == 0 && y > 0) {
          long long out = 0;
          int pt = 0;
          long long Min = INF;
          for (int k = 0; k < max(N, M); k++)
            Min = min(Min, DP[ind ^ 1][1 - i][j][k]);
          for (int k = 1; k < max(N, M); k++) {
            while (pt < V[0][x][y].size() && D[V[0][x][y][pt]] <= k) {
              out += E[V[0][x][y][pt]];
              ++pt;
            }
            if (k != 1)
              DP[ind][i][j][k] =
                  min(DP[ind][i][j][k],
                      DP[ind ^ 1][i][j][k - 1] + AddEnergy[x][y] - out);
            else
              DP[ind][i][j][k] =
                  min(DP[ind][i][j][k], Min + AddEnergy[x][y] - out);
          }
        }
        if (i == 1 && x > 0) {
          long long out = 0;
          long long Min = INF;
          int pt = 0;
          for (int k = 0; k < max(N, M); k++)
            Min = min(Min, DP[ind ^ 1][1 - i][j - 1][k]);
          for (int k = 1; k < max(N, M); k++) {
            while (pt < V[1][x][y].size() && D[V[1][x][y][pt]] <= k) {
              out += E[V[1][x][y][pt]];
              ++pt;
            }
            if (k != 1)
              DP[ind][i][j][k] =
                  min(DP[ind][i][j][k],
                      DP[ind ^ 1][i][j - 1][k - 1] + AddEnergy[x][y] - out);
            else
              DP[ind][i][j][k] =
                  min(DP[ind][i][j][k], Min + AddEnergy[x][y] - out);
          }
        }
      }
    }
  }
  long long ans = INF;
  ind ^= 1;
  for (int k = 0; k < max(N, M); k++) {
    ans = min(ans, DP[ind][0][N - 1][k]);
    ans = min(ans, DP[ind][1][N - 1][k]);
  }
  printf("%I64d\n", ans);
}
int main() {
  Read();
  precalcAddEnergy();
  Solve();
  return 0;
}
