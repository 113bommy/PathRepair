#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  double ans = 0;
  for (int v = 1; v <= 10000; v++) {
    double pr = 0;
    for (int i = 0; i < int(pow(3.0, n) + 0.1); i++) {
      vector<int> st(n), cnt(3);
      int _i = i;
      for (int j = 0; j < n; j++) {
        st[j] = _i % 3;
        cnt[_i % 3]++;
        _i /= 3;
      }
      if (cnt[1] >= 1 && cnt[1] + cnt[2] >= 2 && cnt[2] < 2) {
        double _pr = 1;
        for (int j = 0; j < n; j++) {
          if (st[j] == 0) {
            _pr *=
                1.0 * max(min(r[j], v - 1) - l[j] + 1, 0) / (r[j] - l[j] + 1);
          } else if (st[j] == 1) {
            if (r[j] < v || v < l[j])
              _pr = 0;
            else
              _pr *= 1.0 / (r[j] - l[j] + 1);
          } else {
            _pr *=
                1.0 * max(r[j] - max(v + 1, l[j]) + 1, 0) / (r[j] - l[j] + 1);
          }
        }
        pr += _pr;
      }
    }
    ans += pr * v;
  }
  cout << setprecision(12) << fixed;
  cout << ans << endl;
  return 0;
}
