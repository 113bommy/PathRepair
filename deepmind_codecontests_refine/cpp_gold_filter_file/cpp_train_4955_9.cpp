#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, z;
  string y;
  cin >> x >> z;
  for (int i = 0; i < x.length(); i++) {
    if (x[i] < z[i]) {
      cout << -1 << endl;
      return 0;
    } else if (x[i] > z[i])
      y.push_back(z[i]);
    else
      y.push_back(x[i]);
  }
  cout << y << endl;
  return 0;
}
