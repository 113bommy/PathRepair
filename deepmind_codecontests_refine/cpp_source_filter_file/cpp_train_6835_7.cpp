#include <bits/stdc++.h>
using namespace std;
long long q, t[63], first, second, z;
long long lvl(long long first) {
  for (long long i = 62; i >= 0; i--) {
    if ((1ll << i) <= first) return i;
  }
}
int32_t main() {
  cin >> q;
  while (q--) {
    cin >> first;
    if (first == 1) {
      cin >> first >> second;
      long long k = lvl(first);
      t[k] += second;
      t[k] %= (1ll << k);
      t[k] += (1ll << k);
      t[k] %= (1ll << k);
    } else if (first == 2) {
      cin >> first >> second;
      long long k = lvl(first);
      second %= (1ll << k);
      for (long long i = k; i <= 62; i++) {
        t[i] += second * (1ll << (i - k));
        t[i] %= (1ll << i);
        t[i] += (1ll << i);
        t[i] %= (1ll << i);
      }
    } else {
      cin >> first;
      long long k = lvl(first);
      first += t[k];
      first %= (1 << k);
      first += (1 << k);
      for (long long i = k; i >= 0; i--) {
        long long p = first;
        p -= t[i];
        p %= (1ll << i);
        p += (1ll << i);
        cout << p << ' ';
        first /= 2;
      }
      cout << '\n';
    }
  }
}
