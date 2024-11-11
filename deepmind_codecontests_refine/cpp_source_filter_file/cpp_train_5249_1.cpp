#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, t, r = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == 1) {
      if (!m)
        r++;
      else
        m--;
    } else if (t == 2) {
      if (!m && !k)
        r++;
      else if (!m)
        k--;
      else if (!k)
        m--;
      else
        m--;
    }
  }
  cout << r << endl;
  return 0;
}
