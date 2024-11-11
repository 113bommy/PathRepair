#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    m = (i * (i + 1)) / 2;
    if (m == n) {
      cout << "YES" << endl;
      return 0;
    } else if (i == n) {
      cout << "NO" << endl;
      return 0;
    }
  }
}
