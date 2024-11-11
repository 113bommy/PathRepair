#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  if (r % 2 == 1) {
    r++;
  }
  if (g % 2 == 1) {
    g++;
  }
  if (b % 2 == 1) {
    b++;
  }
  int time = 30;
  while (1) {
    if ((r == 0) && (g == 0) && (b == 0)) {
      break;
    }
    if (r != 0) {
      r -= 2;
    }
    time++;
    if ((r == 0) && (g == 0) && (b == 0)) {
      break;
    }
    if (g != 0) {
      g -= 2;
    }
    time++;
    if ((r == 0) && (g == 0) && (b == 0)) {
      break;
    }
    if (b != 0) {
      b -= 2;
    }
    time++;
    if ((r == 0) && (g == 0) && (b == 0)) {
      break;
    }
  }
  cout << time;
  return 0;
}
