#include <bits/stdc++.h>
using namespace std;
int n, pos, l, r, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> pos >> l >> r;
  if (l == 1 && r == n) {
    cout << 0 << endl;
    return 0;
  }
  if (l == 1) {
    ans = abs(r - pos) + 1;
    cout << ans << endl;
    return 0;
  }
  if (r == n) {
    ans = abs(l - pos) + 1;
    cout << ans << endl;
    return 0;
  }
  if (l == pos) {
    cout << abs(r - l) + 2 << endl;
    return 0;
  }
  if (r == pos) {
    cout << abs(r - l) + 2 << endl;
    return 0;
  }
  ans = min(abs(l - pos), abs(r - pos));
  ans += 2;
  ans += abs(l - r);
  cout << ans << endl;
  return 0;
}
