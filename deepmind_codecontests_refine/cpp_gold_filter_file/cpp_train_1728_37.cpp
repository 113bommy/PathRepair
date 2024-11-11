#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
int main() {
  string s;
  int n;
  cin >> n;
  int l = 1, r = n;
  int ans = 0;
  int pos = 1;
  int t = 1;
  while (l <= r + 1) {
    ++t;
    if (t % 2 == 0) {
      ans += (pos + r) % (n + 1);
      r--;
      pos = r + 1;
    } else {
      l++;
      ans += (l + pos) % (n + 1);
      pos = l;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
