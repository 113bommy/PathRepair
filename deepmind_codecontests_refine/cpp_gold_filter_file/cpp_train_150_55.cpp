#include <bits/stdc++.h>
using namespace std;
bool fill(char x[], int i, int j) {
  if (x[i] == x[i + j] && x[i] == x[i + 2 * j] && x[i] == x[i + 3 * j] &&
      x[i] == x[i + 4 * j])
    return true;
  return false;
}
int main() {
  int n, m = 0;
  ;
  cin >> n;
  char x[105];
  for (int i = 0; i < n; i++) x[i] = '.';
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    if (x[i] == '*') {
      for (int j = 1; j <= n / 4; j++)
        if (fill(x, i, j)) {
          cout << "yes";
          m = 1;
          break;
        }
      if (m == 1) break;
    }
  }
  if (m == 0) cout << "no";
  return 0;
}
