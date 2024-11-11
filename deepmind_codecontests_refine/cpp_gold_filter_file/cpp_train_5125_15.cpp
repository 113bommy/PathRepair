#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, t, r = 0;
    cin >> n >> t;
    bool f = true;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (!i) {
        r += a;
        continue;
      }
      if (f) {
        int q = t / i;
        if (q >= a)
          r += a, t -= i * a;
        else
          r += q, t -= i * q;
        if (!t || t < i) f = false;
      }
    }
    cout << r << endl;
  }
  return 0;
}
