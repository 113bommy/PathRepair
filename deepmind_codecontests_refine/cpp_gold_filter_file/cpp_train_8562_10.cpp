#include <bits/stdc++.h>
using namespace std;
int main() {
  string p;
  cin >> p;
  int b = 1, c = 1, z = 1;
  while (b != p.size()) {
    if (p[b] == p[b - 1]) {
      b++;
      if (z == 5) {
        c++;
        z = 1;
      } else
        z++;
      continue;
    } else {
      c++;
      b++;
      z = 1;
    }
  }
  cout << c << endl;
  return 0;
}
