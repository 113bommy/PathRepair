#include <bits/stdc++.h>
using namespace std;
const int NMAX = 110;
int N, M, K, Piles[NMAX], OKG = 1, OKR = 1, SumG = 0, SumR = 0;
char S[NMAX];
int main() {
  scanf("%i %i %i\n", &N, &M, &K);
  for (int i = 1; i <= N; ++i) {
    gets(S + 1);
    int G = -1, R = -1, NrG = 0, NrR = 0;
    for (int j = 1; j <= M; ++j) {
      if (S[j] == 'G') G = j, NrG++, SumG++;
      if (S[j] == 'R') R = j, NrR++, SumR++;
    }
    if (G != -1 && R != -1) Piles[++Piles[0]] = abs(R - G);
    if (G != -1 && R == -1 && M == NrG) OKG = 0;
    if (G == -1 && R != -1 && M == NrR) OKR = 0;
  }
  if (SumR == 0) OKR = 0;
  if (SumG == 0) OKG = 0;
  bool All0 = 1;
  for (int i = 0; i <= 7; ++i) {
    int Cnt = 0;
    for (int j = 1; j <= Piles[0]; ++j)
      if (Piles[j] & (1 << i)) Cnt++;
    if (Cnt % (K + 1) != 0) All0 = 0;
  }
  if (Piles[0] == 0) {
    if (OKG && OKR)
      printf("Draw");
    else if (OKG)
      printf("First");
    else
      printf("Second");
  } else if (All0)
    printf("Second");
  else
    printf("First");
}
