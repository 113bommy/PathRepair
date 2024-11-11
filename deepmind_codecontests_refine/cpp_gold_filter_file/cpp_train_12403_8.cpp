#include <bits/stdc++.h>
using namespace std;
int n, m, S, sz;
int tab[45][105][105], ile[105];
int main() {
  scanf("%d %d", &n, &m);
  if (n > m) {
    n = n ^ m;
    m = n ^ m;
    n = n ^ m;
  }
  S = (1 << n);
  sz = S - 1;
  for (int i = 0; i < S; i++) {
    ile[i] = ile[i >> 1] + (i & 1);
  }
  for (int i = 1; i <= m + 1; i++) {
    for (int j = 0; j < S; j++) {
      for (int k = 0; k < S; k++) {
        for (int l = 0; l < S; l++) {
          if (((k | (k << 1) | (k >> 1) | j | l) & sz) == sz)
            tab[i][j][k] = max(tab[i][j][k], tab[i - 1][k][l] + n - ile[k]);
        }
      }
    }
  }
  int wynik = 0;
  for (int i = 0; i < S; i++) {
    wynik = max(wynik, tab[m + 1][0][i]);
  }
  printf("%d\n", wynik - n);
  return 0;
}
