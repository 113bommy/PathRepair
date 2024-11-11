#include <bits/stdc++.h>
using namespace std;
int n, k;
int wynik;
char slowo[100005];
int tab[100005][30];
int main() {
  scanf("%s", slowo);
  int dl = strlen(slowo);
  for (int i = 0; i < 26; i++) {
    tab[dl][i] = dl;
  }
  for (int i = dl - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) tab[i][j] = tab[i + 1][j];
    tab[i][slowo[i] - 'a'] = i;
  }
  for (int i = 0; i < dl; i++) {
    for (int j = 2; j >= 0; j--) {
      if (tab[i][j] < dl) {
        printf("%c", j + 'a');
        i = tab[i][j];
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
