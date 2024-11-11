#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, c0 = 0, c1 = 0, cm0 = 0;
  cin >> n;
  while (n--) {
    cin >> i;
    if (i == 1) {
      c1++;
      if (c0 > 0) c0--;
    } else {
      c0++;
      if (cm0 < c0) cm0 = c0;
    }
  }
  cout << c1 + cm0;
  return 0;
}
