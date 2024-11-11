#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << max(27 + 3 * ((r + 1) / 2),
              max(28 + 3 * ((g + 1) / 2), 29 + 3 * ((b + 1) / 2)));
  return 0;
}
