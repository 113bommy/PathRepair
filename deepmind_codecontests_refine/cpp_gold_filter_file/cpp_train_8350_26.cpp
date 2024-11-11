#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    cout << (24 * 60) - (60 * x + y) << endl;
  }
  return 0;
}
