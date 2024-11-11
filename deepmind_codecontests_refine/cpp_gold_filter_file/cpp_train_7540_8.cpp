#include <bits/stdc++.h>
int a[1000];
int pos[1000][1000];
using namespace std;
int main() {
  int n;
  int k;
  int sumy = 0;
  int sumx = 0;
  int maxy = 0;
  int miny = 10000;
  cin >> n;
  k = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sumx += a[i];
    sumy += a[i] * k;
    k *= -1;
    if (sumy <= miny) {
      miny = sumy;
    }
    if (sumy >= maxy) {
      maxy = sumy;
    }
  }
  int x = 0;
  int y = -1 * miny;
  k = 1;
  for (int i = 0; i < n; i++) {
    k *= -1;
    for (int j = 0; j < a[i]; j++) {
      pos[y][x] = k;
      x++;
      if (j < a[i] - 1) {
        y += k;
      }
    }
  }
  for (int i = 1; i <= maxy + (miny * -1); i++) {
    for (int j = 0; j < sumx; j++) {
      if (pos[i][j] == -1)
        cout << "/";
      else if (pos[i][j] == 1)
        cout << "\\";
      else
        cout << " ";
    }
    if (i < maxy + (miny * -1)) cout << endl;
  }
  return 0;
}
