#include <bits/stdc++.h>
using namespace std;
int a, b;
int x[4], y[4];
int main() {
  cin >> a >> b >> x[0] >> y[0] >> x[1] >> y[1];
  for (int i = 0; i < 2; i++) {
    x[i + 2] = ceil((y[i] - x[i]) / (2.0 * a));
    y[i + 2] = ceil((y[i] + x[i]) / (2.0 * b));
  }
  cout << max(abs(x[2] - x[3]), abs(y[2] - y[3]));
  return 0;
}
