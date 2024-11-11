#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int ti = 1; ti <= T; ti++) {
    long long x, y;
    cin >> x >> y;
    if (x - y == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
