#include <bits/stdc++.h>
using namespace std;
int x[8], y[8];
pair<int, int> p[8];
int main() {
  for (int i(0); i != 8; ++i) {
    cin >> x[i] >> y[i];
    p[i] = make_pair(x[i], y[i]);
  }
  sort(x, x + 8);
  int nx = unique(x, x + 8) - x;
  sort(y, y + 8);
  int ny = unique(y, y + 8) - y;
  if (nx != 3 || ny != 3) {
    puts("ugly");
    return 0;
  }
  for (int i(0); i != 2; ++i)
    for (int j(0); j != 2; ++j)
      if (i != 1 || j != 1)
        if (!count(p, p + 8, make_pair(x[i], y[j]))) {
          puts("ugly");
          return 0;
        }
  puts("respectable");
  return 0;
}
