#include <bits/stdc++.h>
using namespace std;
int w, h;
char a[300][300], b[300][300], c[300][300], d[300][300];
int main(void) {
  cin >> w >> h;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> a[i][j];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) b[j][h - i - 1] = a[i][j];
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++) d[i][h - j - 1] = b[i][j];
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++) {
      c[2 * i][2 * j] = c[2 * i + 1][2 * j] = c[2 * i][2 * j + 1] =
          c[2 * i + 1][2 * j + 1] = d[i][j];
    }
  for (int i = 0; i < 2 * w; i++) {
    for (int j = 0; j < 2 * h; j++) cout << c[i][j];
    cout << endl;
  }
  return 0;
}
