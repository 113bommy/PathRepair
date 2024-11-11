#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0, l = 0, r = 0, u = 0, d = 0, a = 0;
  string q;
  cin >> n >> q;
  for (i = 0; i < n; i++) {
    if (q[i] == 'L') l++;
    if (q[i] == 'R') r++;
    if (q[i] == 'U') u++;
    if (q[i] == 'D') d++;
  }
  if (l == r && r != 0) c = l + r + c;
  if (l != r && l != 0 && r != 0) {
    a = min(l, r);
    c += a * 2;
  }
  if (u == d && u != 0) c = l + r + c;
  if (u != d && u != 0 && d != 0) {
    a = min(u, d);
    c += a * 2;
  }
  cout << c;
  return 0;
}
