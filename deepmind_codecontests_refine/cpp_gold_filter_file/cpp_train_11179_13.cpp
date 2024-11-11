#include <bits/stdc++.h>
using namespace std;
int A[10000 + 100], C[30][10000 + 100];
int main() {
  int N, K;
  while (cin >> N >> K) {
    for (int i = 0; i < N; i++) A[i] = 1;
    A[N] = 0;
    int mx = 1;
    for (int k = 0; k < K; k++) {
      for (int i = N; i >= 1; i--) {
        if (A[i] == N - i)
          C[k][i] = N;
        else {
          if (A[i] + mx <= N - i) {
            C[k][i] = N - mx;
            A[i] = A[i] + mx;
          } else {
            C[k][i] = N - ((N - i) - A[i]);
            A[i] = N - i;
          }
        }
      }
      mx = max(A[1], mx);
      for (int i = 1; i < N; i++) cout << C[k][i] << " ";
      cout << C[k][N] << endl;
    }
  }
  return 0;
}
