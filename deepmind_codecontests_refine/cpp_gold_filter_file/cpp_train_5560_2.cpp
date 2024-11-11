#include <bits/stdc++.h>
using namespace std;
int P[2001], H[2001];
long long fact[2001], F[2001], D[2001], C[2001][2001];
void stuff() {
  int i, j;
  C[0][0] = 1;
  for (i = 1; i < 2001; i++) {
    C[i][0] = 1;
    C[0][i] = 0;
  }
  for (i = 1; i < 2001; i++) {
    for (j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if (C[i][j] >= 1000000007) C[i][j] -= 1000000007;
    }
    for (j = i + 1; j < 2001; j++) C[i][j] = 0;
  }
  D[0] = 1;
  D[1] = 0;
  D[2] = 1;
  for (int n = 3; n < 2001; n++) {
    D[n] = (n - 1) * (D[n - 1] + D[n - 2]);
    D[n] %= 1000000007;
  }
  fact[0] = 1;
  for (int i = 1; i < 2001; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
int main() {
  int n;
  cin >> n;
  fill(H + 1, H + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> P[i];
    if (P[i] > 0) H[P[i]] = 1;
  }
  int k = 0;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (H[i] == 0) {
      if (P[i] == -1) {
        k++;
      }
      m++;
    }
  }
  stuff();
  int delta = m - k;
  F[delta] = fact[delta];
  for (n = delta + 1; n <= m; n++) {
    F[n] = fact[n];
    for (int x = 1; x <= n - delta; x++) {
      F[n] -= F[n - x] * C[n - delta][x];
      F[n] %= 1000000007;
    }
    while (F[n] < 0) {
      F[n] += 1000000007;
    }
  }
  cout << F[m] << endl;
  return 0;
}
