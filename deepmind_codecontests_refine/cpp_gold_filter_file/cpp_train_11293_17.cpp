#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  cin >> w >> h;
  char matrix[h][w];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> matrix[i][j];
  char matrix2[w][h];
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      matrix2[i][j] = matrix[h - 1 - j][i];
    }
  }
  int tmp;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h / 2; j++) {
      tmp = matrix2[i][j];
      matrix2[i][j] = matrix2[i][h - j - 1];
      matrix2[i][h - j - 1] = tmp;
    }
  }
  char matrix3[w][2 * h];
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      matrix3[i][2 * j] = matrix2[i][j];
      matrix3[i][2 * j + 1] = matrix2[i][j];
    }
  }
  char matrix4[2 * w][2 * h];
  for (int i = 0; i < 2 * h; i++) {
    for (int j = 0; j < w; j++) {
      matrix4[2 * j][i] = matrix3[j][i];
      matrix4[2 * j + 1][i] = matrix3[j][i];
    }
  }
  for (int i = 0; i < 2 * w; i++) {
    for (int j = 0; j < 2 * h; j++) {
      cout << matrix4[i][j];
    }
    cout << endl;
  }
}
