#include <bits/stdc++.h>
using namespace std;
int main() {
  int na, ma, nb, mb;
  int a[51][51];
  int b[51][51];
  cin >> na >> ma;
  for (int i = 0; i < na; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < ma; j++) a[i][j] = x[j] == '0' ? 0 : 1;
  }
  cin >> nb >> mb;
  for (int i = 0; i < nb; i++) {
    string x;
    cin >> x;
    for (int j = 0; j < mb; j++) b[i][j] = x[j] == '0' ? 0 : 1;
  }
  int x = 0, y = 0, maxSom = 0;
  int som;
  for (int h = -50; h <= 50; h++)
    for (int z = -50; z <= 50; z++) {
      som = 0;
      for (int i = 0; i < na; i++)
        for (int j = 0; j < na; j++)
          if (i + h >= 0 && j + z >= 0 && i + h < nb && j + z < mb)
            som += a[i][j] * b[i + h][j + z];
      if (som > maxSom) {
        maxSom = som;
        x = h;
        y = z;
      }
    }
  cout << x << " " << y;
  return 0;
}
