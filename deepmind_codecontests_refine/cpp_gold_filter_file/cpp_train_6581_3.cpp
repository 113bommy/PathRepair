#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, t, y = 200000, x = 200000, flag = 1, l = 0, r, n;
  string s;
  for (cin >> t; t > 0; t--) {
    cin >> n >> s;
    unordered_map<long long, long long> m;
    l = -1, r = n + 1;
    flag = 1000000 * x + y;
    m[flag] = 1;
    for (i = 0; i < n; i++) {
      if (s[i] == 'L')
        x--;
      else if (s[i] == 'R')
        x++;
      else if (s[i] == 'U')
        y++;
      else
        y--;
      flag = 1000000 * x + y;
      if (m[flag] > 0) {
        if (i - m[flag] + 1 < r - l + 1) {
          l = m[flag];
          r = i + 1;
        }
      }
      m[flag] = i + 2;
    }
    (l > 0 ? cout << l << " " << r : cout << "-1");
    cout << endl;
  }
}
