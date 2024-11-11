#include <bits/stdc++.h>
using namespace std;
char c[9][9];
int a = 1 << 30, b = 1 << 30;
bool can1(int i, int j) {
  for (int k = int(i + 1); k < int(8); k++)
    if (c[k][j] != '.') return 0;
  return 1;
}
bool can2(int i, int j) {
  for (int k = i - 1; k >= 0; k--)
    if (c[k][j] != '.') return 0;
  return 1;
}
int main() {
  for (int i = 0; i < int(8); i++) {
    for (int j = 0; j < int(8); j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < int(8); i++) {
    for (int j = 0; j < int(8); j++) {
      if (c[i][j] == 'B' && can1(i, j))
        a = min(a, 8 - i - 1);
      else if (c[i][j] == 'W' && can2(i, j))
        b = min(b, i);
    }
  }
  a >= b ? cout << "A" : cout << "B";
  return 0;
}
