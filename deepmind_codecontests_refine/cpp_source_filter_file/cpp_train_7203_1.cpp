#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int z = 0, o = 0;
    int even = 0, odd = 0;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i].size() % 2 == 0)
        even++;
      else
        odd++;
      for (int j = 0; j < v[i].size(); j++)
        if (v[i][j] == '0')
          z++;
        else
          o++;
    }
    int ans = 0;
    if (even == n) {
      if (z % 2 == 0 && o & 2 == 0)
        ans = n;
      else
        ans = n - 1;
    } else if (odd == n) {
      if (n % 2 != 0 &&
          ((z % 2 == 0 && o % 2 != 0) || (z % 2 != 0 && o % 2 == 0)))
        ans = n;
      else if (n % 2 == 0 &&
               ((z % 2 == 0 && o % 2 == 0) || (z % 2 != 0 && o % 2 != 0)))
        ans = n;
      else
        ans = n - 1;
    } else {
      ans = n;
    }
    cout << ans << endl;
  }
  return 0;
}
