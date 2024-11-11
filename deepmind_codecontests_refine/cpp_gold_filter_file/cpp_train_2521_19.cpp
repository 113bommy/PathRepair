#include <bits/stdc++.h>
using namespace std;
const int N = 3003;
const int mod = 1000000007;
int n, m, k;
long long C[N][N];
void pre() {
  for (int i = 0; i < N; i++) C[0][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j++)
      C[i][j] = (C[i - 1][j - 1] % mod + C[i][j - 1] % mod) % mod;
}
int main() {
  pre();
  cin >> n >> m >> k;
  cout << (C[2 * k][m - 1] * C[2 * k][n - 1]) % mod;
  return 0;
}
