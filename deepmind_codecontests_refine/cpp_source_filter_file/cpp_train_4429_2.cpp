#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, h;
  cin >> n >> c;
  int **p;
  p = new int *[2];
  int x1 = 0, x2 = 0;
  int point1 = 0, point2 = 0;
  for (int i = 0; i < 2; i++) {
    p[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    x1 += p[1][i];
    h = p[0][i] - (c * x1);
    if (h < 0) {
      point1 += 0;
    } else {
      point1 += h;
    }
  }
  for (int i = n; i > 0; i--) {
    x2 += p[1][i];
    h = p[0][i] - (c * x2);
    if (h < 0) {
      point2 += 0;
    } else {
      point2 += h;
    }
  }
  if (point1 > point2) {
    cout << "Limak";
  } else if (point1 < point2) {
    cout << "Radewoosh";
  } else {
    cout << "Tie";
  }
  return 0;
}
