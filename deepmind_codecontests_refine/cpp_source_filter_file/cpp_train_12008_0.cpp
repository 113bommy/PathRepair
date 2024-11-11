#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:267435456")
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2, v1, v2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  v1 = abs(x1 - x2);
  v2 = abs(x1 - x2);
  if (((v1 == 4 && v2 == 4)) || ((v1 == 4 && v2 == 3)) ||
      (!(v1 == 3 && v2 == 4))) {
    cout << "Second";
    return 0;
  }
  if (v1 <= 4 && v2 <= 4)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
