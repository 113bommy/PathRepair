#include <bits/stdc++.h>
using namespace std;
int main() {
  int vio[11][11] = {false};
  int score = 0;
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  int suma = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vio[a][b] = 1;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int l = i; l <= r; l++) {
        for (int m = j; m <= c; m++) {
          for (int x = i; x <= l; x++) {
            for (int y = j; y <= m; y++) suma += vio[x][y];
          }
          if (suma >= k) score++;
          suma = 0;
        }
      }
    }
  }
  cout << score;
}
