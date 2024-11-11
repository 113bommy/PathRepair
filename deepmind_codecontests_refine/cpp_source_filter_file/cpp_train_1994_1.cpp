#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  vector<int> x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x.push_back(a);
  }
  sort(x.begin(), x.end());
  y.push_back(x[0]);
  for (int i = 0; i < n - 1; i++) {
    if (x[i] != x[i + 1]) y.push_back(x[i + 1]);
  }
  if (y.size() > 3)
    cout << "-1";
  else if (y.size() == 3) {
    if (y[1] - y[0] == y[2] - y[1])
      cout << y[1] - y[0];
    else
      cout << "-1";
  } else if (y.size() == 2) {
    if ((y[0] + y[1]) % 2 == 0)
      cout << (y[1] + y[0]) / 2;
    else
      cout << y[1] - y[0];
  } else
    cout << "0";
}
