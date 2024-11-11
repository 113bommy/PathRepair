#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x, m, l = INT_MAX, r = -1;
    cin >> n >> x >> m;
    for (int i = 0; i < m; i++) {
      long long f, s;
      cin >> f >> s;
      if (r == -1) {
        if (x >= f && x <= s) {
          if (l > f) l = f;
          if (r < s) r = s;
        }
      } else {
        if ((l >= f && l <= s) || (r >= f && r <= s)) {
          l = min(f, l);
          r = max(r, s);
        }
      }
    }
    if (r == -1)
      cout << "1" << endl;
    else
      cout << r - l + 1 << endl;
  }
}
