#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int MaxN = 5e5 + 5;
int T, N, Ans;
int A[MaxN], F[MaxN], G[MaxN], H[MaxN];
int tF[MaxN], tG[MaxN], tH[MaxN];
int main() {
  int i, j;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 0; i <= N; i++) F[i] = G[i] = H[i] = 0;
    for (Ans = 0, i = 1; i <= N; i++) {
      scanf("%d", &A[i]);
      F[A[i]] = (F[A[i]] << 1) % Mod;
      G[A[i]] = (G[A[i]] << 1) % Mod;
      H[A[i]] = (H[A[i]] << 1) % Mod;
      if (!A[i]) F[0]++;
      if (A[i] == 1) G[1]++;
      if (A[i]) F[A[i]] = (F[A[i]] + F[A[i] - 1]) % Mod;
      if (A[i] > 1) {
        G[A[i]] = (G[A[i]] + F[A[i] - 2]) % Mod;
        G[A[i]] = (G[A[i]] + H[A[i] - 2]) % Mod;
      }
      if (A[i] + 2 <= N) H[A[i]] = (H[A[i]] + G[A[i] + 2]) % Mod;
    }
    for (i = 0; i <= N; i++) {
      Ans = (Ans + F[i]) % Mod;
      Ans = (Ans + G[i]) % Mod;
      Ans = (Ans + H[i]) % Mod;
    }
    printf("%d\n", Ans);
  }
  return 0;
}
