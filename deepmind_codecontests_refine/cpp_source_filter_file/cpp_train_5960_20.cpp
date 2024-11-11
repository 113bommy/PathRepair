#include <bits/stdc++.h>
using namespace std;
int main() {
  setlocale(0, "");
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < (4 * k); i++) {
    int c;
    cin >> c;
  }
  cout << m * n + m + n - 3 << endl;
  for (int i = 0; i < (m - 1); i++) cout << "U";
  for (int g = 0; g < (n - 1); g++) cout << "R";
  int x = 0;
  while (x < (m * n - 1)) {
    if (x < (m * n - 1)) {
      for (int i = 0; i < (n - 1); i++) cout << "L";
      x += (m - 1);
    }
    if (x < (m * n - 1)) {
      cout << "D";
      x++;
    }
    if (x < (m * n - 1)) {
      for (int i = 0; i < (n - 1); i++) cout << "R";
      x += (m - 1);
    }
    if (x < (m * n - 1)) {
      cout << "D";
      x++;
    }
  }
  return 0;
}
