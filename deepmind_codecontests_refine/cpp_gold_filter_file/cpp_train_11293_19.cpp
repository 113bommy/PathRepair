#include <bits/stdc++.h>
using namespace std;
string a[200];
char b[200][200], c[500][500];
int w, h;
int main() {
  cin >> w >> h;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < w; ++j)
    for (int i = h - 1; i >= 0; --i) b[j][i] = a[i][j];
  swap(w, h);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      c[i * 2][j * 2] = c[i * 2 + 1][j * 2] = c[i * 2][j * 2 + 1] =
          c[i * 2 + 1][j * 2 + 1] = b[i][j];
  for (int i = 0; i < 2 * h; i++) printf("%s\n", c[i]);
  return 0;
}
