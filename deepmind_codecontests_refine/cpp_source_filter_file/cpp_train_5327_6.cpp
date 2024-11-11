#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == x && n == y)
      cout << n;
    else
      cout << min(x, y) + 1;
    cout << endl;
  }
  return 0;
}
