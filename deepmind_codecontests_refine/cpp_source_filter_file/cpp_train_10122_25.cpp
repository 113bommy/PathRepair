#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    int moves = 0;
    if (a == b) {
      cout << 0 << "\n";
      continue;
    } else if (a < b) {
      int needed = b - a;
      moves = needed % 2 == 1 ? 1 : needed;
    } else {
      int needed = a - b;
      moves = needed % 2 == 0 ? 1 : 2;
    }
    cout << moves << "\n";
  }
  return 0;
}
