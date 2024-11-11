#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x[5] = {0}, y[5] = {0};
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    ++x[i % 5];
  }
  for (int i = 1; i <= m; ++i) {
    ++y[i % 5];
  }
  cout << x[0] * y[0] + x[1] * y[4] + x[2] * y[3] + x[3] * y[2] + x[4] * y[1];
  return 0;
}
