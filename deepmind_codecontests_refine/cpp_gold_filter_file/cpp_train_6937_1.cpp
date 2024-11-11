#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int ans = 0;
  bool out = false;
  if (pos < l) {
    ans += l - pos;
    pos = l;
    out = 1;
  } else if (pos > r) {
    ans += pos - r;
    pos = r;
    out = 1;
  }
  if (l == 1 && r == n) {
    ans += 0;
  } else if (r == n) {
    ans += pos - l + 1;
  } else if (l == 1) {
    ans += r - pos + 1;
  } else
    ans += min(pos - l + r - l + 2, r - pos + r - l + 2);
  cout << ans << "\n";
}
