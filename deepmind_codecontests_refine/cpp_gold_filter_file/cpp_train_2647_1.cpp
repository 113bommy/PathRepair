#include <bits/stdc++.h>
using namespace std;
int main() {
  bool x_[110];
  bool y_[110];
  for (int i = 0; i < 110; i++) x_[i] = 0;
  for (int i = 0; i < 110; i++) y_[i] = 0;
  int n;
  cin >> n;
  int x;
  int y;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cin >> y;
    x_[x] = 1;
    y_[y] = 1;
  }
  int minx = 0;
  for (int i = 0; i < 110; i++) {
    if (x_[i]) minx++;
  }
  int miny = 0;
  for (int i = 0; i < 110; i++) {
    if (y_[i]) miny++;
  }
  if (minx < miny)
    cout << minx;
  else
    cout << miny;
}
