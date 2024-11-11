#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, ct = 0;
  cin >> n >> m;
  bool b[105] = {false};
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> y;
      b[y] = true;
    }
  }
  for (int i = 0; i < 105; i++) {
    if (b[i] == true) {
      ct++;
    }
  }
  if (ct == m) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
