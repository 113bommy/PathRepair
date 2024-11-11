#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, m;
  cin >> x >> y >> m;
  if (m >= (abs(x) + abs(y))) {
    if ((m - (abs(x) + abs(y))) % 2 == 0)
      cout << "Yes";
    else
      cout << "No";
  } else
    cout << "No";
  return 0;
}
