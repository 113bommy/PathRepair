#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e18;
const long long MOD = 1e9 + 7;
const long long sz = 1e5 + 5;
void f_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
int32_t main() {
  f_io();
  long long tc = 1;
  while (tc--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> ans(n);
    for (long long i = 0; i < n; i++) {
      long long flag = 1, a, b;
      cin >> a >> b;
      for (long long j = 0; j < i; j++) {
        if (ans[j].first >= a && ans[j].first <= a + b - 1) {
          flag = 0;
          break;
        }
        if (ans[j].second >= a && ans[j].first <= a + b - 1) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        ans[i].first = a;
        ans[i].second = a + b - 1;
      } else {
        long long start = 1;
        flag = 1;
        while (flag) {
          flag = 0;
          long long en = start + b - 1;
          for (long long j = 0; j < i; j++) {
            if (ans[j].first >= start && ans[j].first <= en) {
              flag = 1;
              start = ans[j].second + 1;
              break;
            }
            if (ans[j].second >= start && ans[j].second <= en) {
              flag = 1;
              start = ans[j].second + 1;
              break;
            }
          }
          if (!flag) ans[i] = {start, en};
        }
      }
    }
    for (long long i = 0; i < n; i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
