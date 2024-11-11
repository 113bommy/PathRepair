#include <bits/stdc++.h>
using namespace std;
int get(char*[], int);
int main() {
  char map[8][8];
  int b = 8, w = 8;
  int temp;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) cin >> map[i][j];
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      temp = 0;
      if (map[i][j] == 'B') {
        for (int a = i + 1; a < 8; a++) {
          if (map[a][j] == '.') {
            temp++;
          } else if (map[a][j] == 'W') {
            temp = 10;
            break;
          }
        }
        if (temp < b) b = temp;
      } else if (map[i][j] == 'W') {
        for (int a = i + 1; a < 8; a++) {
          if (map[a][j] == '.') {
            temp++;
          } else if (map[a][j] == 'B') {
            temp = 10;
            break;
          }
        }
        if (temp < w) w = temp;
      }
    }
  }
  if (w > b)
    cout << "B";
  else
    cout << "A";
}
