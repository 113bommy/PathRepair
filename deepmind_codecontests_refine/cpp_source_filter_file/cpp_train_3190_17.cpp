#include <bits/stdc++.h>
using namespace std;
int main() {
  char tab[12][12];
  int x, y;
  int cont1, cont2, cont3 = 0;
  for (int j = 0; j < 9; j++) {
    scanf(" %[^\n]", tab[j]);
  }
  scanf("%d %d", &x, &y);
  if (x == 1 || x == 4 || x == 7) {
    cont1 = 0;
  } else if (x == 2 || x == 5 || x == 8) {
    cont1 = 1;
  } else if (x == 3 || x == 6 || x == 9) {
    cont1 = 2;
  }
  if (y == 1 || y == 4 || y == 7) {
    cont2 = 0;
  } else if (y == 2 || y == 5 || y == 8) {
    cont2 = 1;
  } else if (y == 3 || y == 6 || y == 9) {
    cont2 = 2;
  }
  if (cont1 == 0) {
    if (cont2 == 0) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 1) {
      for (int i = 0; i < 3; i++) {
        for (int j = 4; j < 7; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 2) {
      for (int i = 0; i < 3; i++) {
        for (int j = 8; j < 11; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    }
  } else if (cont1 == 1) {
    if (cont2 == 0) {
      for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 1) {
      for (int i = 3; i < 6; i++) {
        for (int j = 4; j < 7; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 2) {
      for (int i = 3; i < 6; i++) {
        for (int j = 8; j < 11; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    }
  } else if (cont1 == 2) {
    if (cont2 == 0) {
      for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 1) {
      for (int i = 6; i < 9; i++) {
        for (int j = 4; j < 7; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    } else if (cont2 == 2) {
      for (int i = 6; i < 9; i++) {
        for (int j = 8; j < 11; j++) {
          if (tab[i][j] == '.') {
            tab[i][j] = '!';
            cont3 = 1;
          }
        }
      }
      if (cont3 == 0) {
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 11; j++) {
            if (tab[i][j] == '.') {
              tab[i][j] = '!';
            }
          }
        }
      }
    }
  }
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 11; i++) {
      i < 10 ? printf("%c", tab[j][i]) : printf("%c\n", tab[j][i]);
    }
    if (j == 2 || j == 5) {
      printf("\n");
    }
  }
  return 0;
}
