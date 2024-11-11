#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h1, h2, v1, v2;
  cin >> h1 >> h2;
  cin >> v1 >> v2;
  int vm = v1 - v2, h = h2 - h1;
  if (vm > 0) {
    int dias = 0;
    while (h >= 0) {
      h -= 8 * v1;
      if (h <= 0) {
        break;
      }
      h += 12 * v2;
      h -= 4 * v1;
      dias++;
    }
    cout << dias << endl;
  } else {
    if (h - 8 * v1 <= 0)
      cout << 0 << endl;
    else
      cout << -1 << endl;
  }
}
