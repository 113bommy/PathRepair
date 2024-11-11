#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, w;
  cin >> y, w;
  int ans = 6 - max(y, w) + 1;
  if (ans == 0) {
    cout << "0" << endl;
    return 0;
  }
  if (ans == 4) {
    cout << "2/3" << endl;
    return 0;
  }
  if (ans == 5) {
    cout << "5/6" << endl;
    return 0;
  }
  cout << "1/" << 6 / ans << endl;
}
