#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  vector<long long> v, vv, ww;
  map<long long, long long> m;
  map<long long, long long>::iterator itr;
  long long t = a + b;
  for (long long i = 0; i < t; i++) {
    long long d;
    cin >> d;
    v.push_back(d);
  }
  for (long long i = 0; i < t; i++) {
    long long d;
    cin >> d;
    if (d == 0)
      vv.push_back(v[i]);
    else
      ww.push_back(v[i]);
  }
  sort(vv.begin(), vv.end());
  sort(ww.begin(), ww.end());
  for (long long i = 0; i < b; i++) {
    m[ww[i]] = 0;
  }
  long long cns = 0;
  for (auto k : vv) {
    long long hi = upper_bound(ww.begin(), ww.end(), k) - ww.begin();
    long long lo = hi - 1;
    if (lo < 0) {
      if (hi < ww.size()) m[ww[hi]]++;
    } else if (hi >= ww.size()) {
      if (lo >= 0) {
        m[ww[lo]]++;
      }
    } else {
      if (abs(ww[lo] - k) <= abs(ww[hi] - k)) {
        m[ww[lo]]++;
      } else {
        m[ww[hi]]++;
      }
    }
  }
  for (itr = m.begin(); itr != m.end(); ++itr) {
    cout << itr->second << " ";
  }
}
