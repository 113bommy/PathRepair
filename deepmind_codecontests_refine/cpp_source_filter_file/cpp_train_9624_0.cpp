#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, k, rr, cc, mx;
  cin >> r >> c >> k;
  if (k < r || k < c) {
    mx = max(r / (k + 1) * c, c / (k + 1) * r);
  } else {
    mx = max(c / (k - (r - 1) + 1), r / (k - (c - 1) + 1));
  }
  if (k > r - 1 + c - 1) mx = -1;
  cout << mx << endl;
  return 0;
}
