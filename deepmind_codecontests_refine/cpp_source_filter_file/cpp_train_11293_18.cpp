#include <bits/stdc++.h>
using namespace std;
int main() {
  int h;
  int w;
  cin >> w >> h;
  char a[100][100];
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) cin >> a[i][j];
  char b[200][200];
  for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) b[i][j] = a[h - j - 1][i];
  for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j) a[i][j] = b[i][h - j - 1];
  for (int i = 0; i < w; ++i)
    for (int j = 0; j < h; ++j)
      b[2 * i][2 * j] = b[2 * i + 1][2 * j] = b[2 * i][2 * j + 1] =
          b[2 * i + 1][2 * j + 1] = a[i][j];
  for (int i = 0; i < 2 * w; ++i) {
    for (int j = 0; j < 2 * h; ++j) cout << b[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
