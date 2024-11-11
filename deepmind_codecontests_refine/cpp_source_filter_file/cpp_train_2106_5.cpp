#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, it;
    cin >> n >> it;
    long long int l = it, h = it;
    bool b = 1;
    long long int tl = 0;
    for (int i = 0; i < n; i++) {
      long long int t, li, hi;
      cin >> t >> li >> hi;
      long long int lr = t;
      t -= tl;
      if (!(li > (h + t) || hi < (l - t))) {
        l = max(li, l - t);
        h = min(hi, h + t);
      } else {
        b = 0;
      }
      if (!i) tl = lr;
    }
    if (b) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
