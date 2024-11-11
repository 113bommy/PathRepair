#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e2 + 5;
long long mod;
long long A[maxn], B[maxn][maxn];
long long G[maxn], F[maxn];
void pre() {
  A[1] = A[0] = 1;
  for (int i = 2; i < maxn; i++) A[i] = A[i - 1] * i % mod;
  B[0][0] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j <= i; j++)
      for (int k = 1; k <= i; k++)
        B[i][j] = (B[i][j] + B[i - k][j - 1] * A[k] % mod) % mod;
  for (int i = 1; i < maxn; i++) {
    F[i] = G[i] = A[i];
    for (int k = 1; k < i; k++) {
      G[i] = (G[i] - G[k] * A[i - k] % mod + mod) % mod;
      F[i] = (F[i] - 2 * G[k] % mod * A[i - k] % mod + mod) % mod;
    }
    for (int k = 4; k < i; k++)
      F[i] = (F[i] - B[i][k] * F[k] % mod + mod) % mod;
  }
  F[2] = 2;
}
int main() {
  int t;
  cin >> t >> mod;
  pre();
  while (t--) {
    int n;
    cin >> n;
    cout << F[n] << endl;
  }
  return 0;
}
