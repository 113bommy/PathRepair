#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 17;
const int MOD = 1e9 + 7;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> va;
    vector<long long> sum(m);
    vector<pair<long long, long long> > vp;
    for (size_t i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      va.push_back(a);
      vp.push_back(make_pair(a, b));
    }
    sort(va.begin(), va.end());
    sum[0] = va[0];
    for (size_t i = 1; i < m; i++) {
      sum[i] = sum[i - 1] + va[i];
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
      ;
      long long a = vp[i].first, b = vp[i].second;
      long long pos = upper_bound(va.begin(), va.end(), b) - va.begin();
      long long ch = m - pos;
      ;
      ;
      ;
      ;
      if (a <= b) {
        if (ch <= n - 1) {
          ans = max(ans, sum[m - 1] - (pos ? sum[pos - 1] : 0) + a +
                             (n - ch - 1) * b);
          ;
        } else {
          ans = max(ans, sum[m - 1] - sum[m - n - 1] + a);
          ;
        }
      } else {
        if (ch <= n) {
          ans = max(ans, sum[m - 1] - (pos ? sum[pos - 1] : 0) + (n - ch) * b);
          ;
        } else {
          ans = max(ans, sum[m - 1] - sum[m - n + 1 - 1]);
          ;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
