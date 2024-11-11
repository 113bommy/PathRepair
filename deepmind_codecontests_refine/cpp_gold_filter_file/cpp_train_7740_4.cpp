#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 3;
  long long x[3], y[3];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  if ((x[0] - x[1]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[0] - y[1]) > 0)
    cout << "RIGHT";
  else if ((x[0] - x[1]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[0] - y[1]) == 0)
    cout << "TOWARDS";
  else
    cout << "LEFT";
}
