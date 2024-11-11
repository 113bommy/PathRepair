#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  cout << (((x - y) % 2 + 2) % 2 == 1 && (x - y) >= -1 && !(x > 1 && y == 1) &&
                   y
               ? "Yes"
               : "No")
       << endl;
  return 0;
}
