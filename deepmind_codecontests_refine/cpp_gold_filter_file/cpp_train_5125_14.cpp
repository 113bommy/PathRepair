#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, r = 0;
    cin >> n >> k;
    bool f = true;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (!i) {
        r += a;
        continue;
      }
      if (f) {
        int q = k / i;
        if (q >= a)
          r += a, k -= i * a;
        else
          r += q, k -= i * q;
        if (!k || k < i) f = false;
      }
    }
    cout << r << endl;
  }
  return 0;
}
