#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, vm;
  cin >> v1 >> v2 >> v3 >> vm;
  for (int a1 = 1; a1 <= 100; a1++)
    for (int a2 = 1; a2 <= 100; a2++)
      for (int a3 = 1; a3 <= 100; a3++) {
        if (a1 <= 2 * v1 && 2 * v1 <= 2 * a1 && a2 <= 2 * v2 &&
            2 * v2 <= 2 * a2 && a3 <= 2 * v3 && 2 * v3 <= 2 * a3 &&
            a3 <= 2 * vm && 2 * vm <= 2 * a3 && a2 > 2 * vm && a1 > 2 * vm &&
            a1 > a2 && a2 > a3) {
          cout << a1 << " " << a2 << " " << a3;
          return 0;
        }
      }
  cout << -1;
  return 0;
}
