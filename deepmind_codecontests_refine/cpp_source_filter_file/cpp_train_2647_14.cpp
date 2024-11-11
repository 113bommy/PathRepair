#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, temp;
  cin >> n;
  bool x[1000] = {}, y[1000] = {};
  for (long long i = 0; i < n; ++i) {
    cin >> temp;
    x[temp] = 1;
    cin >> temp;
    y[temp] = 1;
  }
  long long c_x = 0, c_y = 0;
  for (long long i = 0; i < 1001; ++i) {
    if (x[i]) c_x++;
    if (y[i]) c_y++;
  }
  cout << min(c_x, c_y);
}
