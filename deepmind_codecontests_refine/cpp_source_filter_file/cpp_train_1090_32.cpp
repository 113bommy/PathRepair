#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n;
  cin >> h >> n;
  long long root = 1, level = h, cur = n;
  long long ans = 1;
  for (;;) {
    if (level == 0) break;
    long long div = 1 << level;
    div /= 2ll;
    if (root & 1) {
      if (cur > div) {
        ans += div * 2ll;
        cur -= div;
        level--;
      } else {
        root ^= 1;
        level--;
        ans++;
      }
    } else {
      if (cur > div) {
        root ^= 1;
        cur -= div;
        level--;
        ans++;
      } else {
        ans += div * 2ll;
        level--;
      }
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
