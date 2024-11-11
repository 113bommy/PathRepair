#include <bits/stdc++.h>
using namespace std;
int n, t, ant[3001][3001];
void walk(int x, int y) {
  ++ant[x][y];
  while (ant[x][y] >= 4) {
    ant[x][y] -= 4;
    walk(x + 1, y);
    walk(x - 1, y);
    walk(x, y + 1);
    walk(x, y - 1);
  }
  return;
}
int main() {
  cin >> n >> t;
  ant[1500][1500] = n - 1;
  walk(1500, 1500);
  int x, y;
  for (int i = 1; i <= t; ++i) {
    cin >> x >> y;
    if (x > 1500 || y > 1500 || x < -1500 || y < -1500) {
      cout << 0 << endl;
      continue;
    }
    cout << ant[x + 1500][y + 1500] << endl;
  }
  return 0;
}
