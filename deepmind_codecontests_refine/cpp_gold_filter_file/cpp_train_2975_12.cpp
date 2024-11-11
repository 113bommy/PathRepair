#include <bits/stdc++.h>
using namespace std;
int x[3], y[3], dx, dy, xf[3], yf[3];
bool valid[3];
int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < 3; ++i) {
    int j = (i + 1) % 3;
    dx = x[j] - x[i];
    dy = y[j] - y[i];
    int k = (j + 1) % 3;
    xf[k] = x[k] + dx;
    yf[k] = y[k] + dy;
  }
  cout << 3 << endl;
  for (int i = 0; i < 3; ++i) {
    cout << xf[i] << " " << yf[i] << endl;
  }
}
