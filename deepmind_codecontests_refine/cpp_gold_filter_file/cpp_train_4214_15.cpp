#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, y, z, w, i, j, k, l;
  vector<int> v;
  cin >> n;
  if (!n)
    return cout << "YES\n1\n2\n2\n3", 0;
  else if (n == 1) {
    cin >> x;
    cout << "YES\n" << 2 * x << '\n' << 2 * x << '\n' << 3 * x;
    return 0;
  } else if (n == 2) {
    cin >> x >> y;
    for (i = 1; i <= 2000; ++i)
      for (j = 1; j <= 2000; ++j) {
        v.clear();
        v.push_back(i), v.push_back(j), v.push_back(x), v.push_back(y);
        sort(v.begin(), v.end());
        if ((v[1] + v[2]) % 2 == 0 and (v[0] + v[1] + v[2] + v[3]) % 4 == 0 and
            (v[0] + v[1] + v[2] + v[3]) / 4 == (v[1] + v[2]) / 2 and
            (v[1] + v[2]) / 2 == (v[3] - v[0])) {
          cout << "YES\n";
          for (auto it : v)
            if (it != x and it != y)
              cout << it << '\n';
            else if (it == x)
              x = -1;
            else if (it == y)
              y = -1;
          return 0;
        }
      }
  } else if (n == 3) {
    cin >> x >> y >> z;
    for (i = 1; i <= 2000; ++i) {
      v.clear();
      v.push_back(i), v.push_back(x), v.push_back(y), v.push_back(z);
      sort(v.begin(), v.end());
      if ((v[1] + v[2]) % 2 == 0 and (v[0] + v[1] + v[2] + v[3]) % 4 == 0 and
          (v[0] + v[1] + v[2] + v[3]) / 4 == (v[1] + v[2]) / 2 and
          (v[1] + v[2]) / 2 == (v[3] - v[0])) {
        cout << "YES\n";
        for (auto it : v)
          if (it != x and it != y and it != z)
            cout << it << '\n';
          else if (it == x)
            x = -1;
          else if (it == y)
            y = -1;
          else if (it == z)
            z = -1;
        return 0;
      }
    }
  } else {
    cin >> x >> y >> z >> w;
    v.push_back(x), v.push_back(y), v.push_back(z), v.push_back(w);
    sort(v.begin(), v.end());
    if ((v[1] + v[2]) % 2 == 0 and (v[0] + v[1] + v[2] + v[3]) % 4 == 0 and
        (v[0] + v[1] + v[2] + v[3]) / 4 == (v[1] + v[2]) / 2 and
        (v[1] + v[2]) / 2 == (v[3] - v[0])) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
