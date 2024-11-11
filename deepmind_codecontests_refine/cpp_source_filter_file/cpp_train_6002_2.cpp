#include <bits/stdc++.h>
using namespace std;
int n = 0, m = 0, res = 0;
int main() {
  cin >> n >> m;
  while (m > 0) {
    for (int i = 1; i <= n; i++) {
      if (m >= i) {
        m -= i;
      } else {
        cout << m << " ";
        return 0;
      }
    }
  }
}
