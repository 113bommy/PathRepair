#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  char president;
  cin >> r >> c >> president;
  char room[r + 2][c + 2];
  for (int i = 1; i < r + 1; i++)
    for (int j = 1; j < c + 1; j++) cin >> room[i][j];
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < c + 2; j++) room[i][j] = president;
  for (int i = r + 1; i < r + 2; i++)
    for (int j = 0; j < c + 2; j++) room[i][j] = president;
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < r + 2; j++) room[j][i] = president;
  for (int i = c + 1; i < c + 2; i++)
    for (int j = 0; j < r + 2; j++) room[j][i] = president;
  set<char> ss;
  for (int i = 1; i < r; i++)
    for (int j = 1; j < c; j++) {
      if (room[i][j] == president) {
        if (room[i - 1][j] != '.' && room[i - 1][j] != president)
          ss.insert(room[i - 1][j]);
        if (room[i + 1][j] != '.' && room[i + 1][j] != president)
          ss.insert(room[i + 1][j]);
        if (room[i][j - 1] != '.' && room[i][j - 1] != president)
          ss.insert(room[i][j - 1]);
        if (room[i][j + 1] != '.' && room[i][j + 1] != president)
          ss.insert(room[i][j + 1]);
      }
    }
  cout << ss.size();
  return 0;
}
