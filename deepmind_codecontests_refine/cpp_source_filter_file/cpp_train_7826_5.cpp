#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int p = 0; p < t; p++) {
    int x, y;
    cin >> x >> y;
    if ((x - y) > 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
