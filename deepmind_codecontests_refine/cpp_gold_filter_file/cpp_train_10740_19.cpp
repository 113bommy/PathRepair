#include <bits/stdc++.h>
using namespace std;
class trio {
 public:
  long long first, second, third;
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long q;
  cin >> q;
  while (q--) {
    long long b, w, b1, w1;
    cin >> b >> w;
    b1 = b;
    w1 = w;
    if (3 * b + 1 < w || 3 * w + 1 < b) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      long long i = 2;
      while (b && w) {
        cout << 2 << " " << i << endl;
        cout << 2 << " " << i + 1 << endl;
        b--;
        w--;
        i += 2;
      }
      if (b) {
        cout << 2 << " " << 1 << endl;
        b--;
      }
      i = 2;
      while (b) {
        cout << 1 << " " << i << endl;
        b--;
        if (b == 0) break;
        cout << 3 << " " << i << endl;
        b--;
        i += 2;
      }
      if (w) {
        cout << 2 << " " << b1 * 2 + 2 << endl;
        w--;
      }
      i = 3;
      while (w) {
        cout << 1 << " " << i << endl;
        w--;
        if (w == 0) break;
        cout << 3 << " " << i << endl;
        w--;
        i += 2;
      }
    }
  }
  return 0;
}
