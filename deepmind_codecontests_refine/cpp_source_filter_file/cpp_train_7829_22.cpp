#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0, k = 2; i < k; i++, k--) {
    for (int j = 0, l = 2; j < l; j++, l--) {
      if (a[i][j] != a[k][l]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
