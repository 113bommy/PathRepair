#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  if (y < 2 && x != 0) {
    cout << "No"
         << "\n";
    return 0;
  }
  x = x - y - 1;
  if (x % 2 == 0 && x >= 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
