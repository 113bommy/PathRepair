#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, d, h;
  cin >> n >> d >> h;
  int n1 = n;
  if (n == 2) {
    cout << 1 << " " << 2 << endl;
  } else {
    int val = ceil((float)d / (float)2);
    int d1 = d, n1 = n;
    if (h < val)
      cout << -1 << "\n";
    else {
      int st = 1;
      vector<pair<int, int>> v;
      for (int i = 1; i <= h; i++) {
        v.push_back({st, st + 1});
        st++;
      }
      st += 1;
      int rem = d - h;
      if (rem > 0) {
        v.push_back({1, st});
        rem--;
        for (int i = 1; i <= rem; i++) {
          v.push_back({st, st + 1});
          st++;
        }
        st += 1;
      }
      n -= (st - 1);
      if (n < 0)
        cout << -1 << endl;
      else {
        int with = (d == h ? 2 : 1);
        for (int i = 1; i <= n; i++) {
          v.push_back({with, st});
          st++;
        }
        if (n1 > 3 && h <= 1)
          cout << -1 << "\n";
        else
          for (pair<int, int> p : v) cout << p.first << " " << p.second << "\n";
      }
    }
  }
  return 0;
}
