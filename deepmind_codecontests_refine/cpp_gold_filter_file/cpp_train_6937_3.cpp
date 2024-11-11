#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int ans = 0;
  if (l == 1 && r == n) {
    ans = 0;
  } else if (1 == l) {
    ans = abs(r - pos) + 1;
  } else if (n == r) {
    ans = abs(pos - l) + 1;
  } else if (r == l) {
    ans = abs(pos - r) + 2;
  } else if (abs(pos - l) < abs(pos - r)) {
    ans = abs(pos - l) + 1 + (r - l) + 1;
  } else {
    ans = abs(r - pos) + 1 + (r - l) + 1;
  }
  cout << ans << endl;
}
