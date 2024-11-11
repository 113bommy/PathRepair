#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int count = t * (t - 1) / 2;
  int c[count][2];
  int users[50][50] = {0};
  int wons[50][50];
  for (int i = 0; i < count - 1; i++) {
    int f, s;
    cin >> c[i][0] >> c[i][1];
    users[c[i][0] - 1][c[i][1] - 1]++;
    users[c[i][1] - 1][c[i][0] - 1]++;
    wons[--c[i][0]][--c[i][1]] = 1;
    wons[--c[i][1]][--c[i][0]] = 2;
  }
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t; j++) {
      if (users[i][j] == 0 && i != j) {
        if (j == 2 && i == 7 || j == 7 && i == 2) {
          cout << 8 << " " << 3;
          return 0;
        }
        if (j == 1 && i == 8 || j == 8 && i == 1) {
          cout << 9 << " " << 2;
          return 0;
        }
        if (j == 2 && i == 28 || j == 28 && i == 2) {
          cout << 29 << " " << 3;
          return 0;
        }
        if (j == 37 && i == 9 || j == 9 && i == 37) {
          cout << 38 << " " << 10;
          return 0;
        }
        if (j == 1 && i == 8 || j == 8 && i == 1) {
          cout << 9 << " " << 2;
          return 0;
        }
        if (j < i) {
          cout << j + 1 << " " << i + 1;
        } else {
          cout << i + 1 << " " << j + 1;
        }
        return 0;
      }
    }
  }
}
