#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, w;
  cin >> w >> b;
  if (w == 0)
    cout << "0.000000000" << endl;
  else if (b == 0)
    cout << "1.000000000" << endl;
  else if (b == 1)
    printf("%.9f\n", double(w) / (w + 1));
  else if (b == 2)
    printf("%.9f\n", double(w * (w + 1) + 2) / ((w + 1) * (w + 2)));
  else {
    double p[w + 1][b + 1];
    if (b >= 2 * w) {
      for (int col = b - 2 * w; col >= 0; col -= 3) p[0][col] = 0.0;
      int startcol, endcol;
      for (int row = 1; row <= w; row++) {
        startcol = (b + w - row) % 3;
        endcol = b - 2 * (w - row);
        if (startcol == 0)
          p[row][startcol] = 1.0;
        else if (startcol == 1)
          p[row][startcol] = double(row) / (row + 1);
        else
          p[row][startcol] =
              double(row * (row + 1) + 2) / ((row + 1) * (row + 2));
        for (int col = startcol + 3; col <= endcol; col += 3) {
          p[row][col] =
              double(row) / (row + col) +
              (p[row][col - 3] * (col - 2) + p[row - 1][col - 2] * row) * col *
                  (col - 1) / ((row + col) * (row + col - 1) * (row + col - 2));
        }
      }
    } else {
      int startcol, endcol;
      int firstrow = w - b / 2;
      for (int row = firstrow; row <= w; row++) {
        startcol = (b + w - row) % 3;
        endcol = b - 2 * (w - row);
        if (startcol == 0)
          p[row][startcol] = 1.0;
        else if (startcol == 1)
          p[row][startcol] = double(row) / (row + 1);
        else
          p[row][startcol] =
              double(row * (row + 1) + 2) / ((row + 1) * (row + 2));
        for (int col = startcol + 3; col <= endcol; col += 3) {
          p[row][col] =
              double(row) / (row + col) +
              (p[row][col - 3] * (col - 2) + p[row - 1][col - 2] * row) * col *
                  (col - 1) / ((row + col) * (row + col - 1) * (row + col - 2));
        }
      }
    }
    printf("%.9f\n", p[w][b]);
  }
  return 0;
}
