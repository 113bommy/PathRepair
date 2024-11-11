#include <bits/stdc++.h>
using namespace std;
int N, M, C;
char A[55], B[55];
string D[55];
int dp[55][55];
bool ok[55][55];
char a, b, c;
bool pa[55][55][55];
bool pb[55][55][55];
bool same(int ip, int i, int kp, int k) {
  for (int c = 'a' - 'a'; c <= 'z' - 'a'; c++)
    if (pa[ip][i][c] && pb[kp][k][c]) return true;
  return false;
}
void init(int NN, bool p[55][55][55], char X[55]) {
  for (int I = 1; I <= NN; I++) p[I][I][X[I]] = true;
  for (int len = 2; len <= NN; len++) {
    for (int l = 1; l + len - 1 <= NN; l++) {
      int r = l + len - 1;
      for (int I = 1; I <= C; I++) {
        a = D[I][0] - 'a';
        b = D[I][3] - 'a';
        c = D[I][4] - 'a';
        for (int le = l; le < r; le++)
          p[l][r][a] |= p[l][le][b] && p[le + 1][r][c];
      }
    }
  }
}
void print(char* X, int l, int r) {
  for (int I = l; I <= r; I++) cout << char(X[I] + 'a');
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> A + 1 >> B + 1;
  N = strlen(A + 1);
  M = strlen(B + 1);
  for (int I = 1; I <= N; I++) A[I] -= 'a';
  for (int I = 1; I <= M; I++) B[I] -= 'a';
  cin >> C;
  for (int I = 1; I <= C; I++) cin >> D[I];
  init(N, pa, A);
  init(M, pb, B);
  ok[0][0] = true;
  for (int I = 1; I <= N; I++)
    for (int K = 1; K <= N; K++) {
      for (int ip = 1; ip <= I; ip++)
        for (int kp = 1; kp <= K; kp++) {
          if (ok[ip - 1][kp - 1] && same(ip, I, kp, K)) {
            if (!ok[I][K]) {
              ok[I][K] = true;
              dp[I][K] = dp[ip - 1][kp - 1] + 1;
            } else {
              dp[I][K] = min(dp[I][K], dp[ip - 1][kp - 1] + 1);
            }
          }
        }
    }
  if (ok[N][M])
    cout << dp[N][M] << endl;
  else
    cout << -1 << endl;
}
