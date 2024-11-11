#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = 0;
  int x, y;
  cin >> x >> y;
  a = y;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cin >> x >> y;
      while (y <= a) {
        y = y + x;
      }
      a = y;
    }
  }
  cout << a;
  return 0;
}
