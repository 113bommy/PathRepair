#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, j, c = 0;
  cin >> x;
  for (i = 1; i <= x; i++) {
    for (j = i + 1; j <= x; j++) {
      if (j % i == 0 && (j / i) < x && j * i > x && c == 0) {
        cout << j << " " << i << endl;
        c++;
        break;
      }
    }
  }
  if (c == 0) cout << "-1" << endl;
  return 0;
}
