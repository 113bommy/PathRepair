#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, q, r, t;
  int w, h;
  cin >> w >> h;
  long long c = 0;
  for (i = 0; i <= w; i++) {
    for (j = 0; j <= h; j++) {
      c += min(min(i - 0, w - i), min(j - 0, h - j));
    }
  }
  cout << c;
  return 0;
}
