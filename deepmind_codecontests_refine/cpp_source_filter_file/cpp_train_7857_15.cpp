#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  char t[n][n];
  for (int i = 0; i < n; i++) scanf("%s", &t[i]);
  int max = 0;
  for (int i = 0; i < n; i++) {
    int mapa[n], cont = 0;
    for (int j = 0; j < n; j++)
      if (t[i][j] == '0')
        mapa[i] = 0;
      else
        mapa[i] = 1;
    for (int j = 0; j < n; j++) {
      bool limpo = true;
      for (int q = 0; q < n; q++) {
        if ((t[j][q] == '0' && mapa[q] == 1) ||
            (t[j][q] == '1' && mapa[q] == 0)) {
          limpo = false;
          break;
        }
      }
      if (limpo) cont++;
    }
    if (cont > max) max = cont;
  }
  printf("%d\n", max);
  return 0;
}
