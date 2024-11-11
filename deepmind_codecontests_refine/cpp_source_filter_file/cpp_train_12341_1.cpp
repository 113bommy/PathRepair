#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long double eps = 1e-8;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v1;
    vector<long long> v2;
    vector<long long> v3;
    vector<long long> v4;
    long long x[n];
    long long y[n];
    long long z[n];
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> z[i];
      v1.push_back(x[i] + y[i] - z[i]);
      v2.push_back(x[i] - y[i] + z[i]);
      v3.push_back(-x[i] + y[i] + z[i]);
      v4.push_back(x[i] + y[i] + z[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    long long R = 2e18, L = 0;
    long long a = -239, b = -239, c = -239;
    while (R - L > 1) {
      long long mid = (R + L) / 2;
      long long aa2 = v1[0] + mid;
      long long aa1 = v1[n - 1] - mid;
      long long bb2 = v2[0] + mid;
      long long bb1 = v2[n - 1] - mid;
      long long cc2 = v3[0] + mid;
      long long cc1 = v3[n - 1] - mid;
      long long dd2 = v4[0] + mid;
      long long dd1 = v4[n - 1] - mid;
      bool ok = false;
      if (aa2 >= aa1 && bb2 >= bb1 && cc2 >= cc1 && dd2 >= dd1) {
        if (min(aa2 + bb2 + cc2, dd2) >= max(aa1 + bb1 + cc1, dd1)) {
          ok = true;
          a = aa1, b = bb1, c = cc1;
          long long delta = max(0ll, dd1 - a - b - c);
          a += min(delta, aa2 - aa1);
          delta -= min(delta, aa2 - aa1);
          b += min(delta, bb2 - bb1);
          delta -= min(delta, bb2 - bb1);
          c += min(delta, cc2 - cc1);
          delta -= min(delta, cc2 - cc1);
          assert(delta == 0);
        }
      }
      if (ok) {
        R = mid;
      } else {
        L = mid;
      }
    }
    if (a == -239 && b == -239 && c == -239) {
      a = v1[0], b = v2[0], c = v3[0];
    }
    long long ans[3] = {(a + b) / 2, (a + c) / 2, (b + c) / 2};
    long long anss[3] = {ans[0], ans[1], ans[2]};
    long long ans_ = -1;
    for (int i1 = -1; i1 < 2; i1++) {
      for (int i2 = -1; i2 < 2; i2++) {
        for (int i3 = -1; i3 < 2; i3++) {
          long long nw[3] = {ans[0] + i1, ans[1] + i2, ans[2] + i3};
          long long nw_ = 0ll;
          for (int i = 0; i < n; i++) {
            nw_ = max(
                nw_, abs(nw[0] - x[i]) + abs(nw[1] - y[i]) + abs(nw[2] - z[i]));
          }
          if (nw_ < ans_ || ans_ == -1) {
            ans_ = nw_;
            for (int i = 0; i < 3; i++) {
              anss[i] = nw[i];
            }
          }
        }
      }
    }
    for (auto i : anss) {
      cout << i << " ";
    }
    cout << endl;
  }
}
