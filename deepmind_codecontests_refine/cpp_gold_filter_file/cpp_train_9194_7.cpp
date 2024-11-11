#include <bits/stdc++.h>
using namespace std;
long long T, M[105][2505], i, j, k, N, S, t;
char C[105];
int main() {
  cin >> T;
  cin.getline(C, 105);
  for (i = 0; i <= 25; i++) M[1][i] = 1;
  for (i = 2; i <= 100; i++)
    for (j = 0; j <= 2500; j++) {
      for (k = j; k >= 0 && k >= j - 25; k--) {
        M[i][j] += M[i - 1][k];
        M[i][j] %= 1000000007;
      }
    }
  for (t = 1; t <= T; t++) {
    cin.getline(C, 105);
    N = strlen(C);
    S = 0;
    for (i = 0; i < N; i++) S += (C[i] - 'a');
    cout << (M[N][S] + 1000000006) % 1000000007 << "\n";
  }
  return 0;
}
