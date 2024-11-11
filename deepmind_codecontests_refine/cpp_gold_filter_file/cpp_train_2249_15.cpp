#include <bits/stdc++.h>
using namespace std;
const int N = 123;
const int inf = 2123456789;
int n, m;
int lewo = inf, prawo = -inf, gora = inf, dol = -inf;
char tab[N][N];
int ile = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", tab[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (tab[i][j] == 'B') {
        lewo = min(lewo, j);
        prawo = max(prawo, j);
        gora = min(gora, i);
        dol = max(dol, i);
        ile++;
      }
    }
  }
  if (ile == 0) {
    puts("1");
    exit(0);
  }
  int szer = prawo - lewo + 1;
  int wys = dol - gora + 1;
  int wyn = szer * wys - ile;
  bool b = true;
  if (szer > wys) {
    while (gora > 1 && szer > wys) {
      gora--;
      wys++;
      wyn += szer;
    }
    while (dol < n && szer > wys) {
      dol++;
      wys++;
      wyn += szer;
    }
    if (szer > wys) b = false;
  }
  if (szer < wys) {
    while (lewo > 1 && szer < wys) {
      lewo--;
      szer++;
      wyn += wys;
    }
    while (prawo < m && szer < wys) {
      prawo++;
      szer++;
      wyn += wys;
    }
    if (szer < wys) b = false;
  }
  if (!b) {
    printf("-1");
  } else
    printf("%d", wyn);
}
