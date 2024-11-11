#include <bits/stdc++.h>
using namespace std;
int divCount(int n, int d) {
  if (n < 1 || d < 2) return 99999;
  int count = 0;
  int dmod = d;
  while (n % dmod == 0) {
    count++;
    dmod *= d;
  }
  return count;
}
int sc[1001][1001];
char preva[1001][1001];
int board[1001][1001];
void dynProgram(int n, int d) {
  for (int i = (1); i < (n + 1); i++)
    for (int j = (1); j < (n + 1); j++) {
      sc[i][j] = divCount(board[i][j], d);
      if (sc[i][j - 1] <= sc[i - 1][j]) {
        sc[i][j] += sc[i][j - 1];
        preva[i][j] = 'R';
      } else {
        sc[i][j] += sc[i - 1][j];
        preva[i][j] = 'D';
      }
    }
}
int extractPath(char* path, int n, int d) {
  int sc = 0, x = n, y = n;
  for (int i = (0); i < (2 * n - 2); i++) {
    sc += divCount(board[x][y], d);
    char dir = preva[x][y];
    path[2 * n - 3 - i] = dir;
    if (dir == 'D')
      x--;
    else if (dir == 'R')
      y--;
  }
  path[2 * n - 2] = '\0';
  return sc;
}
void body() {
  int n;
  std::cin >> (n);
  int zx = 0, zy;
  for (int i = (1); i < (n + 1); i++)
    for (int j = (1); j < (n + 1); j++) {
      std::cin >> (board[i][j]);
      if (board[i][j] == 0) {
        zx = i;
        zy = j;
      }
    }
  for (int i = (2); i < (n + 1); i++) {
    sc[0][i] = 99999;
    sc[i][0] = 99999;
  }
  dynProgram(n, 2);
  char path2[2 * n - 1];
  int sc22 = sc[n][n], sc25 = extractPath(path2, n, 5);
  int sc2 = min(sc22, sc25);
  dynProgram(n, 5);
  char path5[2 * n - 1];
  int sc55 = sc[n][n], sc52 = extractPath(path5, n, 2);
  int sc5 = min(sc52, sc55);
  if (min(sc2, sc5) > 1 && zx > 0) {
    std::cout << (1) << std::endl;
    for (int i = (1); i < (zx); i++) cout << 'R';
    for (int i = (1); i < (zy); i++) cout << 'D';
    for (int i = (0); i < (n - zx); i++) cout << 'R';
    for (int i = (0); i < (n - zy); i++) cout << 'D';
    cout << endl;
  } else if (sc2 < sc5) {
    std::cout << (sc2) << std::endl;
    std::cout << (path2) << std::endl;
  } else {
    std::cout << (sc5) << std::endl;
    std::cout << (path5) << std::endl;
  }
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cout.sync_with_stdio(false);
  body();
  return 0;
}
