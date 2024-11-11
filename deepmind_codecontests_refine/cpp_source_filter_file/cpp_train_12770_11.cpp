#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  char grid[50][50] = {};
  int mini = min(a, min(b, min(c, d))), line, column;
  char symbol, auxiliary_symbol;
  if (a == mini) {
    symbol = 'A';
    auxiliary_symbol = 'B';
    a = 0;
  } else if (b == mini) {
    symbol = 'B';
    auxiliary_symbol = 'A';
    b = 0;
  } else if (c == mini) {
    symbol = 'C';
    auxiliary_symbol = 'A';
    c = 0;
  } else {
    symbol = 'D';
    auxiliary_symbol = 'A';
    d = 0;
  }
  if (mini <= 25) {
    if (symbol == 'A')
      b--;
    else
      a--;
    for (int i = 0; i < (mini - 1) * 2; i += 2) grid[0][i] = symbol;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 50; j++)
        if (!grid[i][j]) grid[i][j] = auxiliary_symbol;
    for (int i = 2; i < 50; i += 2)
      for (int j = 0; j < 50; j++) grid[i][j] = symbol;
    for (int i = 3; i < 50; i += 2)
      for (int j = 1; j < 50; j += 2) grid[i][j] = symbol;
    line = 3, column = 0;
  } else if (mini <= 50) {
    if (symbol == 'A')
      b -= (mini - 25) + 1;
    else
      a -= (mini - 25) + 1;
    for (int i = 0; i < 50; i += 2) grid[0][i] = symbol;
    for (int i = 0; i < (mini - 26) * 2; i += 2) grid[1][i] = symbol;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 50; j++)
        if (!grid[i][j]) grid[i][j] = auxiliary_symbol;
    for (int i = 3; i < 50; i += 2)
      for (int j = 0; j < 50; j++) grid[i][j] = symbol;
    for (int i = 4; i < 50; i += 2)
      for (int j = 1; j < 50; j += 2) grid[i][j] = symbol;
    line = 4, column = 0;
  } else if (mini <= 75) {
    if (symbol == 'A')
      b -= (mini - 50) + 26;
    else
      a -= (mini - 50) + 26;
    for (int i = 0; i < 50; i += 2) grid[0][i] = symbol;
    for (int i = 1; i < 50; i += 2) grid[1][i] = symbol;
    for (int i = 0; i < (mini - 51) * 2; i += 2) grid[2][i] = symbol;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 50; j++)
        if (!grid[i][j]) grid[i][j] = auxiliary_symbol;
    for (int i = 4; i < 50; i += 2)
      for (int j = 0; j < 50; j++) grid[i][j] = symbol;
    for (int i = 5; i < 50; i += 2)
      for (int j = 1; j < 50; j += 2) grid[i][j] = symbol;
    line = 5, column = 0;
  } else {
    if (symbol == 'A')
      b -= (mini - 75) + 51;
    else
      a -= (mini - 75) + 51;
    for (int i = 0; i < 50; i += 2) grid[0][i] = symbol;
    for (int i = 1; i < 50; i += 2) grid[1][i] = symbol;
    for (int i = 0; i < 50; i += 2) grid[2][i] = symbol;
    for (int i = 0; i < (mini - 76) * 2; i += 2) grid[3][i] = symbol;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 50; j++)
        if (!grid[i][j]) grid[i][j] = auxiliary_symbol;
    for (int i = 5; i < 50; i += 2)
      for (int j = 0; j < 50; j++) grid[i][j] = symbol;
    for (int i = 6; i < 50; i += 2)
      for (int j = 1; j < 50; j += 2) grid[i][j] = symbol;
    line = 6, column = 0;
  }
  while (a > 0) {
    grid[line][column] = 'A';
    column += 2;
    if (column >= 50) {
      line += 2;
      column = 0;
    }
    a--;
  }
  while (b > 0) {
    grid[line][column] = 'B';
    column += 2;
    if (column >= 50) {
      line += 2;
      column = 0;
    }
    b--;
  }
  while (c > 0) {
    grid[line][column] = 'C';
    column += 2;
    if (column >= 50) {
      line += 2;
      column = 0;
    }
    c--;
  }
  while (d > 0) {
    grid[line][column] = 'D';
    column += 2;
    if (column >= 50) {
      line += 2;
      column = 0;
    }
    d--;
  }
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      if (!grid[i][j]) grid[i][j] = symbol;
  cout << "50 50" << endl;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) cout << grid[i][j];
    cout << endl;
  }
  return 0;
}
