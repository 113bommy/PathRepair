#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < 10000; j++) {
    for (int i = 1; i <= n; i++) {
      if (m - i >= 0)
        m -= i;
      else {
        cout << m << endl;
        return 0;
      }
    }
  }
}
