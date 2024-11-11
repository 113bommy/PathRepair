#include <bits/stdc++.h>
char T[10][10];
bool U[10];
bool D[10];
bool fu, fd;
int wynu = 0, wynd = 0;
int main() {
  for (int i = 0; i < 8; i++) scanf("%s", T[i]);
  for (int i = 0; i < 8; i++) {
    if (fu) break;
    for (int j = 0; j < 8; j++) {
      if (T[i][j] == '.') continue;
      if (U[j]) continue;
      if (T[i][j] == 'W') {
        wynu = i;
        fu = true;
        break;
      }
      if (T[i][j] == 'B') U[j] = true;
    }
  }
  for (int i = 7; i >= 0; i--) {
    if (fd) break;
    for (int j = 0; j < 8; j++) {
      if (T[i][j] == '.') continue;
      if (D[j]) continue;
      if (T[i][j] == 'B') {
        wynd = 7 - i;
        fd = true;
        break;
      }
      if (T[i][j] == 'W') D[j] = true;
    }
  }
  printf("%c\n", wynu > wynd ? 'B' : 'A');
}
