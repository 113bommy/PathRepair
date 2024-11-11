#include <bits/stdc++.h>
using namespace std;
int gs(long long x, long long p) {
  int s = 0;
  while (x > 0) {
    x /= p;
    s++;
  }
  return s;
}
int main() {
  long long x, y, l, r;
  cin >> x >> y >> l >> r;
  int sx = gs(r, x), sy = gs(r, y);
  set<long long> guL;
  long long px = 1;
  for (int i = 0; i < sx; i++) {
    long long py = 1;
    for (int j = 0; j < sy; j++) {
      if (l <= px + py && px + py <= r) guL.insert(px + py);
      py *= y;
    }
    px *= x;
  }
  guL.insert(r + 1);
  long long p = l, res = 0;
  for (long long t : guL) {
    res = max(res, t - p - 1);
    p = t;
  }
  cout << res << endl;
}
