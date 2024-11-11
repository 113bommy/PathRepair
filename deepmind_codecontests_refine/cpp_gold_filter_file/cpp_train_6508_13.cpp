#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int INF = 1000000010;
const int MOD = 1000000007;
long long adj[30][110][110];
long long res[110][110];
long long temp[110][110];
int ar[MAXN];
int n, B, K, M, mod;
int main() {
  scanf(" %d %d %d %d", &n, &B, &K, &mod);
  for (int i = 1; i <= n; i++) scanf(" %d", &ar[i]);
  M = mod;
  for (int i = 0; i < M; i++) {
    for (int j = 1; j <= n; j++) adj[0][i][(i * 10 + ar[j]) % mod]++;
  }
  for (int t = 1; t < 30; t++) {
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
        for (int k = 0; k < M; k++) {
          adj[t][i][j] += adj[t - 1][i][k] * adj[t - 1][k][j];
          adj[t][i][j] %= MOD;
        }
  }
  for (int i = 0; i < M; i++) res[i][i] = 1;
  for (int t = 30; t >= 0; t--) {
    if ((1 << t) > B) continue;
    B -= (1 << t);
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++) {
        temp[i][j] = 0;
        for (int k = 0; k < M; k++) {
          temp[i][j] += res[i][k] * adj[t][k][j];
          temp[i][j] %= MOD;
        }
      }
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++) res[i][j] = temp[i][j];
  }
  cout << res[0][K] % MOD << endl;
  return 0;
}
