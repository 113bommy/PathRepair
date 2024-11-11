#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (j = 0; j < n; j++) {
        cout << "#";
      }
      cout << endl;
    } else {
      if (i % 4 == 1) {
        for (j = 0; j < n - 1; j++) {
          cout << ".";
        }
        cout << "#";
        cout << endl;
      } else {
        cout << "#";
        for (j = 1; j < n; j++) {
          cout << ".";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
