#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  bool last = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % 2 == 1)
        cout << "#";
      else {
        if ((j == 1 && !last) || (j == m && last))
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
