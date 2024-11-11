#include <bits/stdc++.h>
using namespace std;
long long N, M, F[300005], S[100005], Cnt3, Ans;
long long Petya[4][300005], Sz[4];
long long P[4][4] = {{0}, {0, 1, 1}, {0, 2, 1}};
bool Cmp(long long X, long long Y) { return X > Y; }
signed main() {
  scanf("%lld%lld", &N, &M);
  for (long long I = 1; I <= N; I++) {
    long long W, C;
    scanf("%lld%lld", &W, &C);
    Petya[W][++Sz[W]] = C, Cnt3 += (W == 3);
  }
  for (long long I = 1; I <= 3; I++)
    sort(Petya[I] + 1, Petya[I] + Sz[I] + 1, Cmp), Sz[I] = M;
  for (long long I = 1; I <= M; I++) S[I] = S[I - 1] + Petya[3][I];
  F[1] = Petya[1][1];
  for (long long I = 2; I <= M; I++) {
    long long Cur = (I & 1) + 1;
    if (Petya[1][P[Cur][1]] + Petya[1][P[Cur][1] + 1] > Petya[2][P[Cur][2]])
      F[I] = F[I - 2] + Petya[1][P[Cur][1]] + Petya[1][P[Cur][1] + 1],
      P[Cur][1] += 2;
    else
      F[I] = F[I - 2] + Petya[2][P[Cur][2]], P[Cur][2]++;
  }
  for (long long I = 0; I <= min(M / 3, Cnt3); I++)
    Ans = max(Ans, S[I] + F[M - I * 3]);
  printf("%lld", Ans);
  return 0;
}
