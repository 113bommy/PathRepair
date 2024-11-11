#include <bits/stdc++.h>
using namespace std;
long long Best[105][105];
map<int, int> M;
int Left[105][105][305], DP[105][305][305];
int N, cnt;
pair<int, int> Light[105];
int X[305], X2[305];
int Pos[105][3];
int Nb[105];
void Read() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> Light[i].first >> Light[i].second;
  sort(Light + 1, Light + N + 1);
  for (int i = 1; i <= N; i++) {
    X[++cnt] = Light[i].first - Light[i].second;
    X[++cnt] = Light[i].first;
    X[++cnt] = Light[i].first + Light[i].second;
  }
  sort(X + 1, X + cnt + 1);
  int cnt2 = 0;
  for (int i = 1; i <= cnt; i++) {
    if (i == 1 || X[i] != X[i - 1]) X2[++cnt2] = X[i];
  }
  cnt = cnt2;
  for (int i = 1; i <= cnt; i++) {
    X[i] = X2[i];
    M[X[i]] = i;
  }
  for (int i = 1; i <= N; i++) {
    Pos[i][0] = M[Light[i].first - Light[i].second];
    Pos[i][1] = M[Light[i].first];
    Pos[i][2] = M[Light[i].first + Light[i].second];
  }
}
void precalcLeft(int L) {
  for (int j = 1; j <= cnt; j++)
    for (int k = 1; k <= cnt; k++) DP[L][j][k] = 0;
  DP[L][Pos[L][1]][Pos[L][1]] = Pos[L][0];
  DP[L][Pos[L][2]][Pos[L][2]] = Pos[L][1];
  for (int i = L; i <= N; i++) {
    for (int j = 1; j <= cnt; j++) {
      for (int k = 1; k <= j; k++) {
        if (DP[i][j][k] == 0) continue;
        int x = Pos[i + 1][0], y = Pos[i + 1][1];
        int newj = max(y, j);
        int newi = min(x, DP[i][j][k]);
        int newt = k;
        if (k >= x) newt = newj;
        if (DP[i + 1][newj][newt] == 0)
          DP[i + 1][newj][newt] = newi;
        else
          DP[i + 1][newj][newt] = min(DP[i + 1][newj][newt], newi);
        x = Pos[i + 1][1];
        y = Pos[i + 1][2];
        newj = max(y, j);
        newi = min(x, DP[i][j][k]);
        newt = k;
        if (k >= x) newt = newj;
        if (DP[i + 1][newj][newt] == 0)
          DP[i + 1][newj][newt] = newi;
        else
          DP[i + 1][newj][newt] = min(DP[i + 1][newj][newt], newi);
        if (j == k) {
          Left[L][i][j] = min(Left[L][i][j], DP[i][j][k]);
        }
        DP[i][j][k] = 0;
      }
    }
  }
}
void precalcBest() {
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= cnt; j++) {
      if (Left[1][i][j] != cnt + 4)
        Best[i][j] = max(Best[i][j], 1LL * (X[j] - X[Left[1][i][j]]));
      for (int k = 0; k < i; k++) {
        for (int l = 0; l <= j; l++) {
          if (Left[k + 1][i][j] < l || Left[k + 1][i][j] == cnt + 4) continue;
          Best[i][j] =
              max(Best[i][j], Best[k][l] + X[j] - X[Left[k + 1][i][j]]);
        }
      }
      if (i == N) ans = max(ans, Best[i][j]);
    }
  }
  cout << ans << "\n";
}
int main() {
  Read();
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j++)
      for (int k = 1; k <= cnt; k++) Left[i][j][k] = cnt + 4;
  for (int i = N; i >= 1; i--) {
    precalcLeft(i);
    for (int j = i; j <= N; j++) {
      for (int k = cnt; k >= 1; k--) {
        if (k < cnt) Left[i][j][k] = min(Left[i][j][k], Left[i][j][k + 1]);
        if (j > i) {
          Left[i][j][k] = min(Left[i][j][k], Left[i + 1][j][k]);
          Left[i][j][k] = min(Left[i][j][k], Left[i][j - 1][k]);
        }
        if (Left[i][j][k] > k) Left[i][j][k] = cnt + 4;
      }
    }
  }
  precalcBest();
  return 0;
}
