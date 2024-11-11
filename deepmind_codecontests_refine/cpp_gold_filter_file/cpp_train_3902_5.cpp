#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      for (int j = 1; j <= m; j++) {
        cout << "#";
      }
      cout << endl;
    } else {
      t++;
      if (t == 1) {
        for (int j = 1; j < m; j++) {
          cout << ".";
        }
        cout << "#" << endl;
        t++;
      } else {
        cout << "#";
        for (int j = 1; j < m; j++) {
          cout << ".";
        }
        cout << endl;
        t = 0;
      }
    }
  }
  return 0;
}
