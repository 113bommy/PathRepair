#include <bits/stdc++.h>
using namespace std;
void solve(int x1, int y1, int x2, int y2, int x3, int y3) {
  cout << x1 + x3 - x2 << ' ';
  cout << y1 + y3 - y2 << ' ';
  cout << '\n';
}
int main() {
  int x1, x2, y1, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cout << 3 << '\n';
  solve(x1, y1, x2, y2, x3, y3);
  solve(x1, y1, x3, y3, x2, y2);
  solve(x2, y2, x3, y3, x1, y1);
  return 0;
}
