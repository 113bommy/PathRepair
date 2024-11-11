#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    if (i % 2 == 1) {
      for (int j = 1; j <= n; j++) cout << "#";
    } else {
      if (i / 2 % 2 == 0) cout << "#";
      for (int j = 1; j < n; j++) cout << ".";
      if (i / 2 % 2 == 1) cout << "#";
    }
    cout << endl;
  }
  return 0;
}
