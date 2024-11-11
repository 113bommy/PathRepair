#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int s = 0;
    int x = 0;
    while (s <= n) {
      x++;
      s += x;
    }
    cout << x - 1 << endl;
    for (int i = 1; i <= x; i++) {
      if (i == (s - n)) continue;
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}
