#include <bits/stdc++.h>
using namespace std;
int couldw(char tab[5][5], int f, int c) {
  if (f <= 1)
    if (tab[f + 1][c] == 'x' && tab[f + 2][c] == 'x') return 1;
  if (f > 0 && f < 3)
    if (tab[f - 1][c] == 'x' && tab[f + 1][c] == 'x') return 1;
  if (f >= 2)
    if (tab[f - 2][c] == 'x' && tab[f - 1][c] == 'x') return 1;
  if (c <= 1)
    if (tab[f][c + 1] == 'x' && tab[f][c + 2] == 'x') return 1;
  if (c > 0 && c < 3)
    if (tab[f][c - 1] == 'x' && tab[f][c + 1] == 'x') return 1;
  if (c >= 2)
    if (tab[f][c - 2] == 'x' && tab[f][c - 1] == 'x') return 1;
  if (f <= 1 && c <= 1)
    if (tab[f + 1][c + 1] == 'x' && tab[f + 2][c + 2] == 'x') return 1;
  if (f >= 1 && f <= 2 && c >= 1 && c <= 2)
    if (tab[f - 1][c - 1] == 'x' && tab[f + 1][c + 1] == 'x') return 1;
  if (f >= 2 && c <= 2)
    if (tab[f - 2][c - 2] == 'x' && tab[f - 1][c - 1] == 'x') return 1;
  if (f >= 2 && c <= 1)
    if (tab[f - 1][c + 1] == 'x' && tab[f - 2][c + 2] == 'x') return 1;
  if (f >= 1 && f <= 2 && c >= 1 && c <= 2)
    if (tab[f + 1][c - 1] == 'x' && tab[f - 1][c + 1] == 'x') return 1;
  if (f <= 1 && c >= 2)
    if (tab[f + 1][c - 1] == 'x' && tab[f + 2][c - 2] == 'x') return 1;
  return 0;
}
int main() {
  char tab[5][5];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> tab[i][j];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (tab[i][j] == '.' && couldw(tab, i, j)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  cout << "NO" << endl;
  return 0;
}
