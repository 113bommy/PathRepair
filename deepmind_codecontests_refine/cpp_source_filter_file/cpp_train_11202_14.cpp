#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y, z;
  string a = "";
  cin >> x >> y >> z;
  for (int i = 0; i < z.size(); i++) {
    if (z[i] >= 'A' && z[i] <= 'Z') {
      z[i] += 32;
      int m = x.find(z[i]);
      a += y[m] - 32;
    } else if (z[i] >= '0' && z[i] <= '9') {
      a += y[i];
    } else {
      int m = x.find(z[i]);
      a += y[m];
    }
  }
  cout << a;
  return 0;
}
