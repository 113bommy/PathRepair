#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = 0, y = 0, z = 0, a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a == 25) {
      x++;
      continue;
    }
    if (a == 50) {
      if (x == 0) {
        cout << "NO";
        return 0;
      } else
        x--, y++;
      continue;
    }
    if (y > 0 && x > 0) {
      z++;
      y--;
      x--;
      continue;
    }
    if (x >= 3) {
      x -= 3;
      z++;
      continue;
    }
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
