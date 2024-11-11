#include <bits/stdc++.h>
using namespace std;
int c[5], z, n, x;
int main() {
  cin >> n;
  while (n--) {
    cin >> x;
    c[x]++;
  }
  z += x = min(c[1], c[2]);
  c[1] -= x;
  c[2] -= x;
  c[3] += x;
  if (c[1]) {
    x = c[1] / 3;
    z += 2 * x;
    c[3] += x;
    c[1] %= 3;
    cout << (!c[1]                    ? z
             : c[1] <= c[3]           ? z + c[1]
             : c[1] == 1 && c[4] >= 2 ? z + 2
             : c[1] == 2 && c[4]      ? z + 2
                                      : -1);
  } else if (c[2]) {
    x = c[2] / 3;
    z += 2 * x;
    c[3] += 2 * x;
    c[2] %= 3;
    cout << (!c[2]                    ? z
             : c[2] <= c[4]           ? z + c[2]
             : c[2] == 1 && c[3] >= 2 ? z + 2
             : c[2] == 2              ? z + 2
                                      : -1);
  } else
    cout << z;
}
