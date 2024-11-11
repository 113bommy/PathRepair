#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b, time = 30;
  cin >> r >> g >> b;
  while (r > 0 || g > 0 || b > 0) {
    if (b > 0) {
      r -= 2;
      g -= 2;
      b -= 2;
      time += 3;
      continue;
    }
    r -= 2;
    g -= 2;
    if (r > 0 || g > 0) {
      time += 3;
      continue;
    }
    if (g >= -1) {
      time += 2;
    } else {
      time += 1;
    }
  }
  cout << time;
  return 0;
}
