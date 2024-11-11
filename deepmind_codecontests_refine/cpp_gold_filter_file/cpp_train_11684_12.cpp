#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, x, n, k, y, n2, g, mn = 1e9, a1, b1, c1, a2, b2, c2,
                                               a3, b3, c3;
long long h[1000000], h2[1000000];
vector<int> ans;
int main() {
  string s, t, t2;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int k = 1; k <= q; k++) {
    ans.clear();
    cin >> a;
    bool flag = 0;
    for (int i = 1; i <= a; i++) {
      cin >> h[i];
      if (h[i] % 2 == 0) {
        flag = 1;
        ans.push_back(i);
      }
    }
    if (flag == 1) {
      cout << 1 << '\n' << ans[0] << '\n';
      continue;
    } else {
      for (int i = 1; i <= a; i++) {
        if (h[i] % 2 != 0) {
          ans.push_back(i);
        }
      }
      if (ans.size() >= 2) {
        cout << 2 << '\n' << ans[0] << " " << ans[1] << '\n';
      } else
        cout << -1 << '\n';
    }
  }
}
