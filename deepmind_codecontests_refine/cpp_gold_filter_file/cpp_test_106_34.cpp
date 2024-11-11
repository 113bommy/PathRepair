#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    int a = 2;
    for (int j = 0; j < m; ++j, ++a) {
      cout << 2 * a + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
