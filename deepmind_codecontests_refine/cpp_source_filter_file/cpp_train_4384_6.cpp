#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, k, s;
  cin >> w >> h >> k;
  while (k != 0) {
    s += w * 2 + (h - 2) * 2;
    --k;
    w -= 4;
    h -= 4;
  }
  cout << s;
  return 0;
}
