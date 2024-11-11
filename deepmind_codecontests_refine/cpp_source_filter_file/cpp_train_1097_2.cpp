#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sumx = 0, sumy = 0, sumz = 0;
  cin >> n;
  while (n--) {
    int x, y, z;
    cin >> x >> y >> z;
    sumx += x;
    sumy += y;
    sumz += z;
  }
  if (sumx == 0 && sumy == 0 && sumz)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
