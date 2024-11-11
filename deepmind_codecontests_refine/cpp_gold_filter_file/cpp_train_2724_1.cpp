#include <bits/stdc++.h>
using namespace std;
int N1, N2, K1, K2;
int dp[102][102][12][12];
int const MOD = 100000000;
int soma(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int solve(int n1, int n2, int k1, int k2) {
  int *atual = &dp[n1][n2][k1][k2];
  if (*atual != -1) return *atual;
  if (n1 > N1 || n2 > N2 || k1 > K1 || k2 > K2) return *atual = 0;
  if (n1 + n2 == N1 + N2) return *atual = 1;
  return *atual =
             soma(solve(n1 + 1, n2, k1 + 1, 0), solve(n1, n2 + 1, 0, k2 + 1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N1 >> N2 >> K1 >> K2;
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 101; j++)
      for (int k = 0; k < 11; k++)
        for (int l = 0; l < 11; l++) dp[i][j][k][l] = -1;
  cout << solve(0, 0, 0, 0) << endl;
}
