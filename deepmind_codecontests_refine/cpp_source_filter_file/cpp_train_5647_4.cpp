#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test_n;
  cin >> test_n;
  while (test_n--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cout << "B ";
    }
    cout << '\n';
    for (int i = 1; i < n; i++) {
      cout << "B ";
      for (int j = 1; j < m; j++) {
        cout << "W ";
      }
      cout << '\n';
    }
  }
  return 0;
}
