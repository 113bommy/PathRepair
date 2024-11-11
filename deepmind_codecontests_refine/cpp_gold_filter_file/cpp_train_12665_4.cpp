#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int field_size, ship_size;
  cin >> field_size;
  cin >> ship_size;
  char field[field_size][field_size];
  for (int i = 0; i < field_size; i++)
    for (int j = 0; j < field_size; j++) cin >> field[j][i];
  int result[field_size][field_size];
  for (int i = 0; i < field_size; i++)
    for (int j = 0; j < field_size; j++) result[i][j] = 0;
  int max_value = 0;
  int max_x = 1;
  int max_y = 1;
  for (int i = 0; i < field_size; i++) {
    for (int j = 0; j < field_size; j++) {
      if (field[i][j] == '#') continue;
      int k;
      if (i <= field_size - ship_size) {
        for (k = i; k < i + ship_size; k++)
          if (field[k][j] == '#') break;
        if (k == i + ship_size) {
          for (int l = i; l < i + ship_size; l++) {
            result[l][j]++;
            if (result[l][j] > max_value) {
              max_value = result[l][j];
              max_x = l + 1;
              max_y = j + 1;
            }
          }
        }
      }
      if (j <= field_size - ship_size) {
        for (k = j; k < j + ship_size; k++)
          if (field[i][k] == '#') break;
        if (k == j + ship_size) {
          for (int l = j; l < j + ship_size; l++) {
            result[i][l]++;
            if (result[i][l] > max_value) {
              max_value = result[i][l];
              max_x = i + 1;
              max_y = l + 1;
            }
          }
        }
      }
    }
  }
  cout << to_string(max_y) + " " + to_string(max_x);
  return 0;
}
