#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a = y * (6 * (x - 1) + 5);
  cout << a << endl;
  for (int i = 0; i < x; i++) {
    cout << y * (6 * i + 1) << " " << y * (6 * i + 2) << " " << y * (6 * i + 3)
         << " " << y * (6 * i + 5) << endl;
  }
  return 0;
}
