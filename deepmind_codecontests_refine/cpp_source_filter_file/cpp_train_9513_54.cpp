#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 3 && m > 4) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 0; i < m; i++) {
      cout << i << " " << 1343132 + i * i << endl;
    }
    for (int i = 0; i < n - m; i++) {
      cout << i << " " << -(1343132 + i * i) << endl;
    }
  }
  return 0;
}
