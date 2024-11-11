#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, k, r, d, l;
  cin >> n >> m >> k;
  l = k % 2;
  k = (k + 1) / 2;
  r = (k - 1) / 3 + 1;
  d = k % 3;
  if (d == 0) {
    d = 3;
  }
  cout << r << ' ' << d << ' ';
  if (l == 0) {
    cout << 'R';
  } else {
    cout << 'L';
  }
  return 0;
}
