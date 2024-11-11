#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int i, j;
  int count = 0;
  for (i = 0; i < n; i++) {
    if (i % 2 != 0) {
      count++;
    }
    if (i % 2 == 0) {
      for (j = 0; j < m; j++) {
        cout << "#";
      }
    } else if (count % 2 != 0) {
      for (j = 0; j < m - 1; j++) {
        cout << ".";
      }
      cout << "#";
    } else {
      cout << "#";
      for (j = 1; j < m; j++) {
        cout << ".";
      }
    }
    cout << "\n";
  }
  return 0;
}
