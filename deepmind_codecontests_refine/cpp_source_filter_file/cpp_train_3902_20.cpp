#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  bool last = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % 2 == 0)
        cout << "#";
      else {
        if ((!last && j == 1) || (last && j == m))
          cout << "#";
        else
          cout << ".";
      }
    }
    if (i % 2 == 0) last = !last;
    cout << endl;
  }
  return 0;
}
