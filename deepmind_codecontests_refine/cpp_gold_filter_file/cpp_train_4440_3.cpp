#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  r -= 2;
  int vreme = 30;
  while (r > 0 || g > 0 || b > 0) {
    g -= 2;
    vreme++;
    if (r <= 0 && g <= 0 && b <= 0) {
      break;
    }
    b -= 2;
    vreme++;
    if (r <= 0 && g <= 0 && b <= 0) {
      break;
    }
    r -= 2;
    vreme++;
    if (r <= 0 && g <= 0 && b <= 0) {
      break;
    }
  }
  cout << vreme;
}
