#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int y = x.size();
  if (y < 2) {
    if ((x[0] - '0') % 4 == 0)
      cout << 4;
    else
      cout << 0;
  } else {
    int z = (x[y - 1] - '0') + (x[y - 2] - '0');
    if (z % 4 == 0)
      cout << 4;
    else
      cout << 0;
  }
}
