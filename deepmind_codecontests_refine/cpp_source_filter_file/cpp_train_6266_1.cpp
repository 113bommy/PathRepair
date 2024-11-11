#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const long long MOD = 998244353;
long long dp[MAXN + 2][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  dp[1][0] = 0;
  dp[1][1] = 1;
  dp[2][0] = 1;
  dp[2][1] = 1;
  int opciones[2];
  int cant_opciones;
  for (int n = 3; n <= N; n++) {
    if (n & 1)
      cant_opciones = 1;
    else
      cant_opciones = 2;
    opciones[0] = (n + 1) / 2;
    opciones[1] = (n + 2) / 2;
    for (int p = 0; p < 2; p++) {
      dp[n][p] = 0;
      for (int i = 0; i < cant_opciones; i++) {
        int x = opciones[i];
        if ((x & 1) != p) continue;
        int buscado = p;
        if (x & 1) buscado = 1 - p;
        long long aux;
        aux = dp[x - 1][1 - p];
        aux = (aux * dp[n - x][buscado]) % MOD;
        dp[n][p] = (dp[n][p] + aux) % MOD;
      }
    }
  }
  long long resp = (dp[N][0] + dp[N][1]) % MOD;
  cout << resp << '\n';
  return 0;
}
