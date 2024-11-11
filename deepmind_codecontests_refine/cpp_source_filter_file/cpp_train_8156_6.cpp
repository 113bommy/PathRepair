#include <bits/stdc++.h>
using namespace std;
int a, b, x, y, l, m, c[10000], i, j, p;
int main() {
  cin >> x >> y;
  cin >> a >> b;
  for (i = a; i <= x; i++) {
    for (j = b; j <= y; j++) {
      if (i > j) {
        c[p] = i;
        c[p + 1] = j;
        p += 2;
      }
    }
  }
  cout << p << endl;
  for (i = 0; i < p; i += 2) {
    cout << c[i] << " " << c[i + 1] / 2 << endl;
  }
  cout << endl;
}
