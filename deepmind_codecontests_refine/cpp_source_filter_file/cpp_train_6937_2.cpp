#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int ans = 0;
  if (l != 1 && r == n)
    ans += abs(pos - l) + 1;
  else if (r != n && l == 1)
    ans += abs(pos - r + 1);
  else if (r != n && l != 1)
    ans += r - l + min(abs(pos - l) + 1, abs(pos - r) + 1) + 1;
  cout << ans << endl;
}
