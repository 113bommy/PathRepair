#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if ((x == 2 && y == 2) || x == 1 || y == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
