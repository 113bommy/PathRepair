#include <bits/stdc++.h>
using namespace std;
int a, b;
int calc2(int x, int a) {
  if (x >= 0) return x / a / 2;
  return -((-x) / a / 2 + 1);
}
pair<int, int> calc(int x, int y) {
  return make_pair(calc2(x + y, a), calc2(x - y, b));
}
int abs(int n) {
  if (n >= 0)
    return n;
  else
    return -n;
}
int calc2(int a, int b, int c, int d) {
  int dist = abs(d - b);
  int a1 = dist + abs(a + dist - c);
  int a2 = dist + abs(a - dist - c);
  return min(a1, a2);
}
int main() {
  int x1, x2, y1, y2;
  while (cin >> a >> b >> x1 >> y1 >> x2 >> y2) {
    pair<int, int> z1 = calc(x1, y1);
    pair<int, int> z2 = calc(x2, y2);
    cout << min(calc2(z1.first, z1.second, z2.first, z2.second),
                calc2(z1.second, z1.first, z2.second, z2.first))
         << endl;
  }
  return 0;
}
