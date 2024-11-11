#include <bits/stdc++.h>
using namespace std;
const int oo = 1e8;
int N, M;
char A[1100], B[1100];
int dp[1100][1100], op[1100][1100];
int NO = 4;
int CH = 1;
int EL = 2;
int IN = 3;
void print(int n, int m) {
  assert(n >= 0 && m >= 0);
  if (n == 0 && m == 0) return;
  if (op[n][m] == NO) {
    print(n - 1, m - 1);
    return;
  }
  if (op[n][m] == CH) {
    print(n - 1, m - 1);
    cout << "REPLACE " << m << " " << B[m] << endl;
  } else if (op[n][m] == IN) {
    print(n, m - 1);
    cout << "INSERT " << m << " " << B[m] << endl;
  } else if (op[n][m] == EL) {
    print(n - 1, m);
    cout << "DELETE " << m << endl;
  } else {
    assert(false);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> A + 1 >> B + 1;
  N = strlen(A + 1);
  M = strlen(B + 1);
  for (int I = 1; I <= N; I++) dp[I][0] = I, op[I][0] = EL;
  for (int K = 1; K <= M; K++) dp[0][K] = K, op[0][K] = IN;
  dp[0][0] = 0;
  for (int I = 1; I <= N; I++)
    for (int K = 1; K <= M; K++) {
      dp[I][K] = oo;
      if (A[I] == B[K]) {
        dp[I][K] = dp[I - 1][K - 1];
        op[I][K] = NO;
      }
      if (A[I] != B[K]) {
        dp[I][K] = dp[I - 1][K - 1] + 1;
        op[I][K] = CH;
      }
      if (dp[I][K - 1] + 1 < dp[I][K]) {
        dp[I][K] = dp[I][K - 1] + 1;
        op[I][K] = IN;
      }
      if (dp[I - 1][K] + 1 < dp[I][K]) {
        dp[I][K] = dp[I - 1][K] + 1;
        op[I][K] = EL;
      }
    }
  cout << dp[N][M] << endl;
  print(N, M);
}
