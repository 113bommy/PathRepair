#include <bits/stdc++.h>
using namespace std;
int n, m;
bool l;
int main() {
  int i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    if (i % 2) {
      for (j = 1; j <= m; j++) {
        cout << '#';
      }
    } else {
      if (!l) {
        for (j = 1; j < m; j++) {
          cout << '.';
        }
        cout << '#';
      } else {
        cout << '#';
        for (j = 2; j <= m; j++) {
          cout << '.';
        }
      }
      l = !l;
    }
    cout << '\n';
  }
  return 0;
}
