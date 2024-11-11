#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long sum = x + y;
  cout << sum / z << ' ';
  long long xx = x % z, yy = y % z;
  if (xx + yy < z) {
    cout << 0;
    return 0;
  }
  cout << min(abs(z - (x % z)), abs(z - (y % z)));
}
