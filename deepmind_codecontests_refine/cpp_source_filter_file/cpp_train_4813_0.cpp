#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    int f, g, h;
    cin >> a >> b >> c;
    int x = 1e12;
    for (int i = 1; i <= 10000; i++) {
      for (int o = i; o <= 10000; o += i) {
        for (int q = o; q <= 10000; q += o) {
          int y = abs(i - a) + abs(o - b) + abs(q - c);
          if (y < x) {
            x = y;
            f = i;
            g = o;
            h = q;
          }
        }
      }
    }
    cout << x << endl << f << ' ' << g << ' ' << h << endl;
  }
}
