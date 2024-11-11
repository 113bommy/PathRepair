#include <bits/stdc++.h>
using namespace std;
int mod1 = int(1e9) + 7;
int cr[1000100];
int rowcnt[1000100];
int main() {
  int n, m, dx, dy;
  cin >> n >> m >> dx >> dy;
  int x = 0, y = 0;
  for (int i = 0; i < (int)(n); ++i) {
    x += dx;
    x %= n;
    y += dy;
    y %= n;
    cr[y] = x;
  }
  for (int i = 0; i < (int)(m); ++i) {
    cin >> x >> y;
    if (x < cr[y]) x += n;
    rowcnt[x - cr[y]]++;
  }
  int tr = 0;
  for (int i = 0; i < (int)(n); ++i) {
    tr += rowcnt[i];
  }
  if (tr != m) cout << "shit" << endl;
  int mmax = -1;
  int mmx = -1;
  for (int i = 0; i < (int)(n); ++i) {
    if (rowcnt[i] > mmax) {
      mmax = rowcnt[i];
      mmx = i;
    }
  }
  cout << mmx << " " << 0 << endl;
  return 0;
}
