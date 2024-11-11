#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
long long a[110];
int main() {
  int q;
  cin >> q;
  long long x, k, r, l, mod;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> x >> k;
      l = log2(x);
      mod = (1ll << l);
      a[l] = (a[l] + k) % mod;
      if (a[l] < 0) a[l] += mod;
    } else if (t == 2) {
      cin >> x >> k;
      l = log2(x);
      while (l < 60) {
        mod = (1ll << l);
        k %= mod;
        a[l] = (a[l] + k) % mod;
        if (a[l] < 0) a[l] += mod;
        l++;
        k *= 2ll;
      }
    } else {
      cin >> x;
      l = log2(x);
      r = x - (1ll << l) + 1;
      mod = (1ll << l);
      r = r + a[l];
      if (r > mod) r = r - mod;
      while (l) {
        mod = (1ll << l);
        k = r - a[l];
        if (k <= 0) k = mod + k;
        cout << (1ll << l) - 1 + k << " ";
        r = (r + 1) / 2;
        l--;
      }
      cout << "1\n";
    }
  }
  return 0;
}
