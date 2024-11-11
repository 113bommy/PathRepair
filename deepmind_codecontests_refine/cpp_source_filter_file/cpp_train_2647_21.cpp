#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x1[101] = {0}, y1[101] = {0}, x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    x1[x]++;
    y1[x]++;
  }
  int cx = 0, cy = 0;
  for (int j = 0; j < 101; j++) {
    if (x1[j] != 0) {
      cx += 1;
    }
  }
  for (int j = 0; j < 101; j++) {
    if (y1[j] != 0) {
      cy += 1;
    }
  }
  cout << min(cx, cy);
  return 0;
}
