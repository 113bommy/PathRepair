#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long N, K;
long long C[60][60];
long long F[60][60][2];
void Pre() {
  C[1][1] = 1;
  for (long long i = 1; i <= N; i++) C[i][0] = 1;
  for (long long i = 2; i <= N; i++)
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
}
int main() {
  scanf("%I64d%I64d", &N, &K);
  Pre();
  F[0][0][1] = 1;
  F[1][0][0] = 1;
  for (long long p = 2; p <= N; p++) {
    for (long long q = 0; q <= p / 2; q++) {
      for (long long i = 0; i <= (p - 1) / 2; i++) {
        for (long long j = 0; j <= i / 2; j++) {
          long long k0 = 1, k1 = 1;
          if (i == p - i - 1) k0++;
          if (i == p - i - 1) k1++;
          long long A = i;
          long long B = p - i - 1;
          if (A == 0) A++;
          long long cz = ((C[p - 1][i] / k0) * A * B) % Mod;
          cz = (cz * F[i][j][1]) % Mod;
          cz = (cz * F[p - i - 1][q - j][1]) % Mod;
          F[p][q][0] = (F[p][q][0] + cz) % Mod;
          cz = ((C[p - 1][i] / k1) * A * B) % Mod;
          cz = (cz * ((F[i][j][1] * F[p - i - 1][q - j - 1][0]) % Mod +
                      (F[i][j][0] * F[p - i - 1][q - j - 1][1]) % Mod +
                      (F[i][j][0] * F[p - i - 1][q - j - 1][0]) % Mod)) %
               Mod;
          F[p][q][1] = (F[p][q][1] + cz) % Mod;
        }
      }
    }
  }
  printf("%I64d\n", (F[N][K][0] + F[N][K][1]) % Mod);
  return 0;
}
