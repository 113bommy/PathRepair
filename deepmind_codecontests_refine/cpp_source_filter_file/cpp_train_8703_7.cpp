#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  bool key = false;
  long long cur = y;
  while (!key && cur >= x) {
    if (cur % k == 0) {
      long long temp = cur;
      cur /= k;
      if (cur >= l && cur <= r) key = true;
      cur = temp;
    }
    cur--;
  }
  if (key)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
