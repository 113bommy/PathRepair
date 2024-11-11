#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long e = 0, o = 0;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] % 2)
        o++;
      else
        e++;
    }
    if (o > e) {
      cout << e + (o - e) / 2 << endl;
    } else {
      cout << o << endl;
    }
  }
}
