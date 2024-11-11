#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int main() {
  srand(time(NULL));
  int x, y, z;
  cin >> x >> y >> z;
  int x1, y4, z1;
  cin >> x1 >> y4 >> z1;
  int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  int ans = 0;
  if (y >= y4 && y != 0) {
    ans += a2;
  }
  if (y < y4 && y != 0) {
    ans += a1;
  }
  if (x >= x1 && x != 0) {
    ans += a6;
  }
  if (x < x1 && x != 0) {
    ans += a5;
  }
  if (z >= z1 && z != 0) {
    ans += a4;
  }
  if (z < z1 && z != 0) {
    ans += a3;
  }
  cout << ans;
  return 0;
}
