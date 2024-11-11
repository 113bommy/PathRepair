#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<double> mass(n);
  for (int i = 0; i < n; i++) {
    cin >> mass.at(i);
  }
  double step;
  step = mass[1] - mass[0];
  for (int i = 0; i < n; i++) {
    if (mass[i] - mass[i - 1] != step) {
      cout << mass[n - 1] << endl;
      return 0;
    }
  }
  cout << mass[n - 1] + step << endl;
  return 0;
}
