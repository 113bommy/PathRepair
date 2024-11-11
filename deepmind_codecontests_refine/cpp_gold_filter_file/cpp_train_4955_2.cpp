#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y;
  cin >> x >> y;
  string z = "";
  for (int i = 0; i < x.size(); i++) {
    if (x[i] < y[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  for (int i = 0; i < y.size(); i++) {
    if (x[i] > y[i])
      z += y[i];
    else
      z += x[i];
  }
  cout << z << endl;
}
