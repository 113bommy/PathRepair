#include <bits/stdc++.h>
using namespace std;
void past_code();
int main() {
  int x, y, z;
  cin >> x;
  while (x--) {
    cin >> y >> z;
    cout << 9 * (y - 1) + z << endl;
  }
  return 0;
}
