#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
      int z;
      cin >> z;
      if (z % 2)
        x.push_back(i + 1);
      else
        y.push_back(i + 1);
    }
    if (x.size() >= 2) {
      cout << 2 << endl;
      cout << x[0] << " " << x[1] << endl;
    } else if (y.size() >= 1) {
      cout << 1 << endl;
      cout << y[0] << endl;
    } else
      cout << -1 << endl;
  }
}
