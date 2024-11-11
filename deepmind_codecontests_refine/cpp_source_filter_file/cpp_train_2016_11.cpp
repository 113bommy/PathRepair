#include <bits/stdc++.h>
using namespace std;
const int Maxn = 50010;
const int Maxs = 35;
int tot;
int n, P;
int F[Maxs][Maxs][Maxn];
int hIndex, hXor, hMod;
int toHash(int i0, int x0, int m0) {
  int Ret = 0;
  Ret = i0 * (P + 10) * 35 + x0 * (P + 10) + m0;
  return Ret;
}
void getHash(int Hash) {
  hIndex = Hash / ((P + 10) * 35);
  Hash -= hIndex * ((P + 10) * 35);
  hXor = Hash / (P + 10);
  Hash -= hXor * (P + 10);
  hMod = Hash % (P + 10);
}
int num[Maxs];
int loc[Maxs];
int Ans;
int pos[Maxs];
int tmp;
int main() {
  scanf("%d%d", &n, &P);
  tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    if (tmp <= 33) {
      ++tot;
      num[tot] = tmp;
      loc[tot] = i;
    }
  }
  memset(F, -1, sizeof(F));
  F[0][0][0] = 0;
  for (int i = 1; i <= tot; i++) {
    for (int j = 0; j < i; j++) {
      for (int xo = 0; xo <= 33; xo++) {
        for (int mo = 0; mo < P; mo++) {
          if (F[j][xo][mo] != -1) {
            F[i][xo ^ num[i]][(mo * (num[i] >= 10 ? 100 : 10) + num[i]) % P] =
                toHash(j, xo, mo);
          }
        }
      }
    }
  }
  for (int i = 1; i <= tot; i++)
    if (F[i][0][0] != -1) {
      Ans = 1;
      getHash(F[i][0][0]);
      while (hIndex != 0) {
        Ans++;
        getHash(F[hIndex][hXor][hMod]);
      }
      pos[Ans] = loc[i];
      getHash(F[i][0][0]);
      for (int j = Ans - 1; j >= 1; j--) {
        pos[j] = loc[hIndex];
        getHash(F[hIndex][hXor][hMod]);
      }
      printf("Yes\n");
      printf("%d\n", Ans);
      for (int j = 1; j <= Ans; j++) printf("%d ", pos[j]);
      printf("\n");
      return 0;
    }
  printf("No\n");
  return 0;
}
