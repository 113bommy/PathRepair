#include <bits/stdc++.h>
using namespace std;
int a = 101, b = 101, c = -101, d = -101, Xcentre, Ycentre, T[8];
bool inside_square(int x, int y) {
  return (x >= a && x <= c && y >= b && y <= d);
}
bool inside_diamond(int x, int y) {
  return ((abs(x - Xcentre) + abs(y - Ycentre)) <=
          (abs(T[0] - Xcentre) + abs(T[1] - Ycentre)));
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < 8; i++) cin >> T[i];
  for (int i = 0; i < 7; i += 2) {
    a = min(a, T[i]), c = max(c, T[i]);
    b = min(b, T[i + 1]), d = max(d, T[i + 1]);
  }
  for (int i = 0; i < 8; i++) cin >> T[i];
  for (int i = 0; i < 7; i += 2) Xcentre += T[i], Ycentre += T[i + 1];
  Xcentre /= 4, Ycentre /= 4;
  for (int i = -100; i <= 100; i++)
    for (int j = -100; j <= 100; j++)
      if (inside_diamond(i, j) && inside_square(i, j)) return cout << "YES", 0;
  cout << "NO";
  return 0;
}
