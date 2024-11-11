#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  bool flag = true;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i % 2 && j < m && flag)
          cout << '.';
        else if (i % 2 && j == m && flag)
          cout << '#';
        else if (i % 2 && j == 1 && !flag)
          cout << '#';
        else if (i % 2 && j > 1 && !flag)
          cout << '.';
        else
          cout << '#';
      }
      if (i % 2) flag = !flag;
      cout << '\n';
    }
  }
  return 0;
}
