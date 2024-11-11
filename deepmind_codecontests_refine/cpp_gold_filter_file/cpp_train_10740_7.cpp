#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q, b, w;
  cin >> q;
  string s1, s2;
  while (q--) {
    cin >> b >> w;
    if (b >= w) {
      if (b > 3 * w + 1) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      long long mb = b, mw = w, i = 1;
      while (mw > 0) {
        cout << 2 << " " << i << "\n";
        cout << 2 << " " << i + 1 << "\n";
        mb--;
        mw--;
        i += 2;
      }
      if (mb > 0) {
        cout << 2 << " " << i << "\n";
        mb--;
      }
      long long r = 2, j = 1, k = 3;
      while (mb > 0) {
        cout << j << " " << r << "\n";
        mb--;
        if (!mb) break;
        cout << k << " " << r << "\n";
        mb--;
        r += 2;
      }
    } else {
      if (w > 3 * b + 1) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      long long mb = b, mw = w, i = 1;
      while (mb > 0) {
        cout << 3 << " " << i << "\n";
        cout << 3 << " " << i + 1 << "\n";
        mb--;
        mw--;
        i += 2;
      }
      if (mw > 0) {
        cout << 3 << " " << i << "\n";
        mw--;
      }
      long long r = 2, j = 2, k = 4;
      while (mw > 0) {
        cout << j << " " << r << "\n";
        mw--;
        if (!mw) break;
        cout << k << " " << r << "\n";
        mw--;
        r += 2;
      }
    }
  }
}
