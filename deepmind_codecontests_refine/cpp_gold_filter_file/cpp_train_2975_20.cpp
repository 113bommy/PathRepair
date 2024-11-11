#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, a, i, k, x[100], y[100];
  for (i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }
  cout << "3" << endl;
  cout << x[2] - x[1] + x[0] << " " << y[0] + y[2] - y[1] << endl;
  cout << x[1] + x[0] - x[2] << " " << y[1] + y[0] - y[2] << endl;
  cout << x[2] + x[1] - x[0] << " " << y[2] + y[1] - y[0] << endl;
}
