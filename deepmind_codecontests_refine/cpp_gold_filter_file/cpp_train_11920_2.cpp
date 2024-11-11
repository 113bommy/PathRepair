#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, s = 0, t, l = -1, r, f;
  cin >> n;
  r = n;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    if (s == 0 && i != t) {
      l = i;
      s = 1;
    } else if (s == 1) {
      if (t != f - 1 && t != i) {
        cout << "0 0";
        return 0;
      }
      if (t == i && t > f) {
        s = 2;
        r = i - 1;
      }
    } else if (s == 2) {
      if (t != i) {
        cout << "0 0";
        return 0;
      }
    }
    f = t;
  }
  if (l == -1)
    cout << "0 0";
  else
    cout << l << " " << r;
}
