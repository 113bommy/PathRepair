#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  cin >> n >> w;
  int mm = 0, mp = 0;
  int re = 0;
  for (int i = 0, j; i < n; ++i) {
    cin >> j;
    re += j;
    if (re < 0) {
      if (mm < -re) mm = -re;
    } else if (mp < re)
      mp = re;
  }
  cout << max(w - mp - mm, 0);
  return 0;
}
