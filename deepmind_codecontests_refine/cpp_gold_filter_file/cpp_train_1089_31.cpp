#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n;
  cin >> h >> n;
  long long l = 1, r = 1ll << h;
  long long ans = 0;
  int level = 0;
  int i = 0;
  while (level < h) {
    ans++;
    long long m = (l + r) / 2;
    if (n >= l && n <= m) {
      if (i % 2 == 1) ans += (1ll << (h - level)) - 1, i++;
      r = m;
    } else {
      if (i % 2 == 0) ans += (1ll << (h - level)) - 1, i++;
      l = m + 1;
    }
    level++;
    i++;
  }
  cout << ans;
  return 0;
}
