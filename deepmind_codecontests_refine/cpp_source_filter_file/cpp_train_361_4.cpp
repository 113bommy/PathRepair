#include <bits/stdc++.h>
using namespace std;
int att[30][3];
int pot[30];
map<pair<int, int>, int> mapa;
map<pair<int, int>, int> res;
char s[3][5] = {"MW", "LW", "MW"};
int main(void) {
  int n;
  pair<int, int> code;
  int max_grat = -0x3f3f3f3f;
  pot[0] = 1;
  for (int i = 1; i < 30 / 2; i++) {
    pot[i] = 3 * pot[i - 1];
  }
  scanf(" %d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf(" %d", &att[i][j]);
    }
  }
  for (int mask = 0; mask < pot[n / 2]; mask++) {
    int a = 0;
    int b = 0;
    int c = 0;
    int aux = mask;
    for (int j = 0; j < n / 2; j++) {
      a += att[j][0];
      b += att[j][1];
      c += att[j][2];
      if (aux % 3 == 0) {
        a -= att[j][0];
      } else if (aux % 3 == 1) {
        b -= att[j][1];
      } else {
        c -= att[j][2];
      }
      aux /= 3;
    }
    pair<int, int> idx = make_pair(a - b, b - c);
    if (mapa.find(idx) == mapa.end()) {
      mapa[idx] = a;
      res[idx] = mask;
    }
    int grat = mapa[idx];
    if (grat < a) {
      mapa[idx] = a;
      res[idx] = mask;
    }
  }
  for (int mask = 0; mask < pot[n - (n / 2)]; mask++) {
    int a = 0;
    int b = 0;
    int c = 0;
    int aux = mask;
    for (int j = 0; j < n - (n / 2); j++) {
      a += att[(n / 2) + j][0];
      b += att[(n / 2) + j][1];
      c += att[(n / 2) + j][2];
      if (aux % 3 == 0) {
        a -= att[(n / 2) + j][0];
      } else if (aux % 3 == 1) {
        b -= att[(n / 2) + j][1];
      } else {
        c -= att[(n / 2) + j][2];
      }
      aux /= 3;
    }
    pair<int, int> idx = make_pair(b - a, c - b);
    if (mapa.find(idx) != mapa.end()) {
      int grat = a + mapa[idx];
      if (grat > max_grat) {
        max_grat = grat;
        code = make_pair(res[idx], mask);
      }
    }
  }
  if (max_grat == -0x3f3f3f3f) {
    printf("Impossible\n");
  } else {
    int aux = code.first;
    for (int i = 0; i < n / 2; i++) {
      printf("%s\n", s[aux % 3]);
      aux /= 3;
    }
    aux = code.second;
    for (int i = 0; i < n - (n / 2); i++) {
      printf("%s\n", s[aux % 3]);
      aux /= 3;
    }
  }
  return 0;
}
