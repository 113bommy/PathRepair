#include <bits/stdc++.h>
using namespace std;
vector<string> field(3);
bool IsWinner(int y, int x) {
  int count[4], px[] = {0, 1, 1, 1}, py[] = {1, 0, 1, -1};
  for (int i = 0; i < 4; i++) {
    count[i] = 1;
    int cury = y + py[i], curx = x + px[i];
    while (cury < 3 && cury >= 0 && curx < 3 && curx >= 0)
      if (field[cury][curx] == field[y][x])
        count[i]++, cury += py[i], curx += px[i];
      else
        break;
    cury = y - py[i], curx = x - px[i];
    while (cury < 3 && cury >= 0 && curx < 3 && curx >= 0)
      if (field[cury][curx] == field[y][x])
        count[i]++, cury -= py[i], curx -= px[i];
      else
        break;
  }
  for (int i = 0; i < 4; i++)
    if (count[i] >= 3) return 1;
  return 0;
}
int main() {
  int cross = 0, null = 0;
  for (int i = 0; i < 3; i++) {
    cin >> field[i];
    for (int j = 0; j < 3; j++)
      if (field[i][j] == 'X')
        cross++;
      else if (field[i][j] == '0')
        null++;
  }
  if (null > cross || cross - null > 1) {
    printf("illegal");
    return 0;
  }
  bool winner1 = 0, winner2 = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (field[i][j] != '.')
        if (IsWinner(i, j)) {
          if (field[i][j] == 'X')
            winner1 = 1;
          else
            winner2 = 1;
        }
  if ((winner1 && (cross + null) % 2 == 0) || (winner2 && (cross + null) % 2)) {
    printf("illegal");
    return 0;
  }
  if (winner1)
    printf("the first player won");
  else if (winner2)
    printf("the second player won");
  else {
    if (cross + null == 9)
      printf("draw");
    else if ((cross + null) % 2)
      printf("second");
    else
      printf("first");
  }
  return 0;
}
