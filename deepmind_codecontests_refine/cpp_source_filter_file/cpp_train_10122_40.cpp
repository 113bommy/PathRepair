#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, m;
  while (t--) {
    int cnt = 0;
    cin >> n >> m;
    if (n == m) {
      cout << 0 << endl;
    } else if (n > m) {
      if (n % 2 == 0 && m % 2 != 0 || n % 2 != 0 && m % 2 == 0)
        cout << 2 << endl;
      else
        cout << 2 << endl;
    } else {
      if (n % 2 == 0 && m % 2 != 0 || n % 2 != 0 && m % 2 == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
