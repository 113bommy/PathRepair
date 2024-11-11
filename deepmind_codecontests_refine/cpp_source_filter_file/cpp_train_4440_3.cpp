#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b, i = 0, res = 30;
  cin >> r >> g >> b;
  while ((r + g + b) > 0) {
    if (i == 0) {
      if (r > 1)
        r -= 2;
      else if (r == 1)
        r--;
    } else if (i == 1) {
      if (g > 1)
        g -= 2;
      else if (g == 1)
        g--;
    } else {
      if (b > 1)
        b -= 2;
      else if (b == 1)
        b--;
    }
    i++;
    i %= 3;
    res++;
  }
  cout << res;
  return 0;
}
