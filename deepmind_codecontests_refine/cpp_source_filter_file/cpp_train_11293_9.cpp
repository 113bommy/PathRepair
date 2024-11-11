#include <bits/stdc++.h>
using namespace std;
const int MAXW = 101, MAXH = 101;
char mas[MAXH][MAXW];
char dispose[MAXW][MAXH];
char mashtab[2 * MAXW][2 * MAXH];
int main() {
  int w = 0, h = 0;
  char symb;
  cin >> w >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> symb;
      mas[i][j] = symb;
    }
  }
  swap(w, h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dispose[i][w - 1 - j] = mas[j][i];
    }
  }
  if (w % 2 == 0) {
    for (int j = 0; j < h; j++) {
      for (int i = 0; i < w / 2; i++) {
        swap(dispose[j][w / 2 + i], dispose[j][w / 2 - (i + 1)]);
      }
    }
  } else {
    for (int j = 0; j < h; j++) {
      for (int i = 0; i < w / 2; i++) {
        swap(dispose[j][w / 2 + (1 + i)], dispose[j][w / 2 - (i + 1)]);
      }
    }
  }
  int p = 0;
  for (int i = 0; i <= 2 * h; i += 2) {
    int k = 0;
    for (int j = 0; j <= 2 * w; j += 2) {
      mashtab[i][j] = dispose[i - p][j - k];
      k++;
    }
    p++;
  }
  for (int i = 0; i <= 2 * h; i += 2) {
    for (int j = 1; j <= 2 * w; j += 2) {
      mashtab[i][j] = mashtab[i][j - 1];
      mashtab[i + 1][j] = mashtab[i][j];
      mashtab[i + 1][j - 1] = mashtab[i][j];
    }
  }
  for (int i = 0; i <= 2 * h; i++) {
    for (int j = 0; j <= 2 * w; j++) {
      cout << mashtab[i][j];
    }
    if (i != 2 * h - 1) cout << endl;
  }
  return 0;
}
