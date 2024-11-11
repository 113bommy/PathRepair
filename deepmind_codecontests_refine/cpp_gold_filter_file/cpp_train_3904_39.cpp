#include <bits/stdc++.h>
using namespace std;
int main() {
  int row, col, k;
  cin >> row >> col >> k;
  for (int(i) = 0; (i) < (k); ++(i)) {
    int pr, pc;
    cin >> pr >> pc;
    if (min(min(pr - 1, pc - 1), min(row - pr, col - pc)) < 5) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
