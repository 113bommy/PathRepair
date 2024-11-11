#include <bits/stdc++.h>
#pragma optimizitaion_level 3
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> kek, cnt;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (kek.empty() || kek.back() != a) {
        kek.push_back(a);
        cnt.push_back(1);
      } else {
        cnt.back()++;
      }
    }
    n = cnt.size();
    int g = cnt[0], s = 0, b = 0, i = 1;
    for (; i < n && s <= g; i++) {
      s += cnt[i];
    }
    for (; i < n && b <= g; i++) {
      b += cnt[i];
    }
    if (s <= g || b <= g) {
      cout << "0 0 0\n";
      continue;
    }
    if (s + b + g <= n / 2) {
      for (; i < n; i++) {
        if (g + s + b + cnt[i] <= n / 2) {
          b += cnt[i];
        } else
          break;
      }
      cout << g << " " << s << " " << b << '\n';
    } else
      cout << "0 0 0\n";
  }
  return 0;
}
