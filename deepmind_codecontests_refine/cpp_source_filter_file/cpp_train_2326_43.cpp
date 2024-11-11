#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, x1, w = 0;
  cin >> x;
  cin >> y;
  for (int i = 0; i < y; i++) {
    cin >> x1;
    if (x1 < x) w += x - x1;
  }
  cout << w << "\n";
}
