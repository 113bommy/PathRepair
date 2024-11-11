#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << 303 << endl;
  cout << "0 1000000\n";
  int prev = 100000;
  for (int i = 2; i <= 302; ++i) {
    prev += 2 * (301 - i) + 2;
    cout << prev << " " << 303 - i << "\n";
  }
  cout << "1000000 1000000";
  return 0;
}
