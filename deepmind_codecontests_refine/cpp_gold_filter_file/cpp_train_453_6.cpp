#include <bits/stdc++.h>
using namespace std;
const int MX = 2005;
const int MOD = 1000000007;
long long D[MX][MX], T[MX][MX], E[MX][MX];
long long tot[MX];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int j = 2; j <= M; j++) D[1][j] = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= M; j++) D[i][j] = (D[i][j - 1] + D[i - 1][j]) % MOD;
    for (int j = 2; j <= M; j++) D[i][j] = (D[i][j] + D[i][j - 1]) % MOD;
  }
  for (int j = 2; j <= M; j++) {
    for (int i = 1; i <= N; i++) D[i][j] = (D[i][j] + D[i - 1][j]) % MOD;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) E[i][j] = (E[i][j - 1] + D[i][j]) % MOD;
    for (int j = 1; j <= M; j++) E[i][j] = (E[i][j - 1] + E[i][j]) % MOD;
    for (int j = 1; j <= M; j++) E[i][j] = (E[i][j] - D[i][j] + MOD + 1) % MOD;
  }
  long long ans = 0;
  for (int j = 2; j <= M; j++) {
    long long tmp = D[N][j];
    for (int k = 1; k < N; k++) {
      tmp = (tmp + D[k][j] * E[N - k][j]) % MOD;
    }
    ans = (ans + tmp * (M - j + 1)) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
