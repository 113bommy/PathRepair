#include <bits/stdc++.h>
using namespace std;
int N, K, V, M, X, Y, i, j, A[5005];
long long TA, Q, B[5005], D[5005][5005];
bool T[5005][5005], S[5005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K >> V;
  M = V % K;
  Q = V / K;
  for (i = 1; i < K; i++) {
    D[0][i] = 10000;
  }
  for (i = 1; i <= N; i++) {
    cin >> A[i];
    TA += A[i];
    B[i] = A[i] / K;
    A[i] = A[i] % K;
    for (j = 0; j < K; j++) {
      D[i][j] = D[i - 1][j];
    }
    for (j = 0; j < K; j++) {
      if (j + A[i] >= K) {
        if (D[i - 1][j] + 1 < D[i][j - K + A[i]]) {
          D[i][j - K + A[i]] = D[i - 1][j] + 1;
          T[i][j - K + A[i]] = 1;
        }
      } else {
        if (D[i - 1][j] < D[i][j + A[i]]) {
          D[i][j + A[i]] = D[i - 1][j];
          T[i][j + A[i]] = 1;
        }
      }
    }
  }
  if (TA < V || D[N][M] == 10000) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (M == 0) {
    for (i = 1; i < N; i++) {
      cout << B[i] + 1 << ' ' << i << ' ' << N << '\n';
    }
    if (Q) {
      cout << Q << ' ' << N << ' ' << 1 << '\n';
    }
    return 0;
  }
  Y = M;
  for (i = N; i > 0; i--) {
    if (T[i][Y]) {
      S[i] = 1;
      Y = (Y + K - A[i]) % K;
    }
  }
  if (S[1]) {
    for (i = 2; i <= N; i++) {
      if (S[i]) {
        cout << B[i] + 1 << ' ' << i << ' ' << 1 << '\n';
        B[1] += B[i];
        B[i] = 0;
        A[1] += A[i];
        A[i] = 0;
        if (A[1] >= K) {
          A[1] -= K;
          B[1]++;
        }
      }
    }
    for (i = 3; i <= N; i++) {
      if (!S[i]) {
        cout << B[i] + 1 << ' ' << i << ' ' << 2 << '\n';
        B[2] += B[i];
        B[i] = 0;
        A[2] += A[i];
        A[i] = 0;
        if (A[2] >= K) {
          A[2] -= K;
          B[2]++;
        }
      }
    }
    if (B[1]) {
      cout << B[1] << ' ' << 1 << ' ' << 2 << '\n';
    }
    if (Q) {
      cout << Q << ' ' << 2 << ' ' << 1 << '\n';
    }
    return 0;
  }
  for (i = 2; i <= N; i++) {
    if (!S[i]) {
      cout << B[i] + 1 << ' ' << i << ' ' << 1 << '\n';
      B[1] += B[i];
      B[i] = 0;
      A[1] += A[i];
      A[i] = 0;
      if (A[1] >= K) {
        A[1] -= K;
        B[1]++;
      }
    }
  }
  for (i = 3; i <= N; i++) {
    if (S[i]) {
      cout << B[i] + 1 << ' ' << i << ' ' << 2 << '\n';
      B[2] += B[i];
      B[i] = 0;
      A[2] += A[i];
      A[i] = 0;
      if (A[2] >= K) {
        A[2] -= K;
        B[2]++;
      }
    }
  }
  if (B[2]) {
    cout << B[2] << ' ' << 2 << ' ' << 1 << '\n';
  }
  if (Q) {
    cout << Q << ' ' << 1 << ' ' << 2 << '\n';
  }
}
