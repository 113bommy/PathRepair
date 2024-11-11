#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> x(3), y(3), pos(1003);
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
    pos[x[i]] = y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  cout << x[2] - x[0] + y[2] - y[0] + 1 << endl;
  for (int i = x[0]; i < x[1]; i++) {
    cout << i << " " << pos[i] << endl;
  }
  for (int i = x[1] + 1; i <= x[2]; i++) {
    cout << i << " " << pos[i] << endl;
  }
  for (int i = y[0]; i <= y[2]; i++) {
    cout << x[1] << " " << i << endl;
  }
  return 0;
}
