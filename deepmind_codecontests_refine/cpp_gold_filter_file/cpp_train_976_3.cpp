#include <bits/stdc++.h>
using namespace std;
int x, y, T;
int F[140][140];
void f(int x, int y) {
  if (F[x][y] < 4) return;
  int g = F[x][y] / 4;
  F[x][y] %= 4;
  F[x + 1][y] += g;
  f(x + 1, y);
  F[x - 1][y] += g;
  f(x - 1, y);
  F[x][y + 1] += g;
  f(x, y + 1);
  F[x][y - 1] += g;
  f(x, y - 1);
}
int main() {
  cin >> F[70][70] >> T;
  f(70, 70);
  while (T--) {
    cin >> x >> y;
    if (x < -70 || x >= 70 || y < -70 || y >= 70)
      cout << "0\n";
    else
      cout << F[x + 70][y + 70] << "\n";
  }
}
