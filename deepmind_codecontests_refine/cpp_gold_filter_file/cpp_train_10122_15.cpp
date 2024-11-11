#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (m > n) {
      if ((m - n) % 2 != 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    } else if (n > m) {
      if ((n - m) % 2 == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
