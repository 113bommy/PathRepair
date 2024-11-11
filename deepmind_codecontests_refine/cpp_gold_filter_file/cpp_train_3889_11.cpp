#include <bits/stdc++.h>
using namespace std;
int Row, Col;
int v;
long long A, B, C, D, E;
int main() {
  scanf("%d %d", &Row, &Col);
  long long px, py;
  for (int r = 0; r < Row; r++) {
    for (int c = 0; c < Col; c++) {
      scanf("%d", &v);
      px = (long long)(4 * c + 2);
      py = (long long)(4 * r + 2);
      A += (long long)v;
      B += (long long)v;
      C += px * v * (-2);
      D += py * v * (-2);
      E += px * px * v + py * py * v;
    }
  }
  int bestR = -1, bestC = -1;
  long long bestV = LONG_LONG_MAX;
  long long value;
  for (int r = 0; r <= Row; r++) {
    for (int c = 0; c <= Col; c++) {
      px = (long long)(4 * c);
      py = (long long)(4 * r);
      value = A * px * px + B * py * py + C * px + D * py + E;
      if (value < bestV) {
        bestV = value;
        bestR = r;
        bestC = c;
      }
    }
  }
  cout << bestV << "\n" << bestR << " " << bestC << "\n";
  return 0;
}
