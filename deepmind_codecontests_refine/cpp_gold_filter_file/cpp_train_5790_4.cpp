#include <bits/stdc++.h>
using namespace std;
int N, M, L, P, H = 1000000000, X, i, j, k, A[5000][5000];
bool B[5000];
char C;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  L = max(M, N);
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      cin >> C;
      A[i][j] = C - '0';
    }
  }
  for (i = 1; i < 2 * L; i++) {
    for (j = 1; j < 2 * L; j++) {
      A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
    }
  }
  for (i = 2; i <= L; i++) {
    if (!B[i]) {
      P = 0;
      for (j = 0; i * j < N; j++) {
        for (k = 0; i * k < M; k++) {
          X = A[(j + 1) * i][(k + 1) * i] - A[j * i][(k + 1) * i] -
              A[(j + 1) * i][k * i] + A[j * i][k * i];
          P += min(X, i * i - X);
        }
      }
      H = min(H, P);
      for (j = i; i * j <= L; j++) {
        B[i * j] = 1;
      }
    }
  }
  cout << H << '\n';
}
