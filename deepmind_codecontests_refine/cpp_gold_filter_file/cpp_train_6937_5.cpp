#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int count = 0;
  if (l == 1 && r == n) {
    cout << 0 << '\n';
  } else if (l == 1) {
    if (pos > r)
      count = pos - r;
    else
      count = r - pos;
    count++;
    cout << count << '\n';
  } else if (r == n) {
    if (pos < l)
      count = l - pos;
    else
      count = pos - l;
    count++;
    cout << count << '\n';
  } else {
    if (pos > r) {
      count = pos - l;
      count += 2;
    } else if (pos < l) {
      count = r - pos;
      count += 2;
    } else {
      count = min(2 * r - l - pos, r + pos - 2 * l);
      count += 2;
    }
    cout << count << '\n';
  }
}
