#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, z;
  cin >> n;
  long long int sumx = 0;
  long long int sumy = 0;
  long long int sumz = 0;
  for (int i = 0; i < 3 * n; i++) {
    cin >> x >> y >> z;
    sumx += x;
    sumy += y;
    sumz += z;
  }
  if (sumx == 0 && sumy == 0 && sumz == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
