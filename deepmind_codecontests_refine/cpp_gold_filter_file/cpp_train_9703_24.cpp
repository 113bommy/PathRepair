#include <bits/stdc++.h>
using namespace std;
int A[200][200] = {}, Max;
int get_max(int N) {
  int S = 0, X = 0;
  while (S <= N) {
    ++X;
    S += X;
  }
  return X - 1;
}
void cr_matrix(int K, int S, int q) {
  for (int j = K, s = 0; j <= Max; ++j, ++s) A[K][j] = S + s;
  for (int i = K + 1, s = 0; i <= Max + 1; ++i, ++s) A[i][K] = S + s;
  S += Max - q;
  ++K;
  if (Max * Max > S) cr_matrix(K, S, q + 1);
}
int main() {
  int N, K;
  cin >> N;
  Max = get_max(N);
  cr_matrix(1, 1, 0);
  cout << Max + 1 << endl;
  for (int i = 1; i <= Max + 1; ++i) {
    for (int j = 1; j <= Max; ++j) cout << A[i][j] << " ";
    cout << endl;
  }
  return 0;
}
