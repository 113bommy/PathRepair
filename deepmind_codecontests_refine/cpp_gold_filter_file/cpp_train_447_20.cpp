#include <bits/stdc++.h>
using namespace std;
int pole[30][30];
int main() {
  int n;
  cin >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      int z;
      cin >> z;
      pole[y][x] = z;
    }
  }
  int res = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      int sumX = 0;
      for (int xx = 0; xx < n; xx++) {
        if (xx == x) continue;
        sumX += pole[y][xx];
      }
      int sumY = 0;
      for (int yy = 0; yy < n; yy++) {
        if (yy == y) continue;
        sumY += pole[yy][x];
      }
      if (sumY > sumX) {
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
