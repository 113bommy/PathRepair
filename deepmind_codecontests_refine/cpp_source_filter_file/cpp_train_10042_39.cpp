#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    if ((i * (i + 1)) / 2 == m) {
      cout << "YES" << endl;
      return 0;
    }
    if ((i * (i + 1)) / 2 > m) {
      cout << "NO" << endl;
      return 0;
    }
  }
  return 0;
}
