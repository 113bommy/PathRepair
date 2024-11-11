#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int A[2][5005], B[2][5005];
int main() {
  cin >> N >> M >> K;
  for (int i = 1; i <= K; ++i) {
    int type, x, a;
    cin >> type >> x >> a;
    A[type][x] = a;
    B[type][x] = i;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (B[1][i] > B[2][j])
        cout << A[1][i] << ' ';
      else
        cout << A[2][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
