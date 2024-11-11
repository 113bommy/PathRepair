#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (k == 1) {
      for (int j = 0; j < m; j++) {
        cout << "#";
      }
      cout << "\n";
      k = 2;
    } else if (k == 2) {
      for (int j = 0; j < m - 1; j++) {
        cout << ".";
      }
      cout << "#\n";
      k = 3;
    } else if (k == 3) {
      for (int j = 0; j < m; j++) {
        cout << "#";
      }
      cout << "\n";
      k = 4;
    } else {
      cout << "#";
      k = 1;
      for (int j = 0; j < m - 1; j++) {
        cout << ".";
      }
      cout << "\n";
    }
  }
  return (0);
}
