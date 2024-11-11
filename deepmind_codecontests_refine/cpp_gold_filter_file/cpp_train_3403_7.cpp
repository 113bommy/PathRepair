#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long power(long long a, long long b);
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      long long ele;
      cin >> ele;
      s.insert(ele);
    }
    long long ans = 1;
    vector<long long> res;
    res.push_back(*s.begin());
    for (auto x : s) {
      long long val = x;
      long long temp = 1;
      for (long long i = 0; i < 31; i++) {
        if (s.count(val + (1ll << i))) {
          temp++;
          if (s.count(val + (1ll << (i + 1)))) {
            temp++;
            if (temp > ans) {
              res = {val, val + (1ll << i), val + (1ll << (i + 1))};
              ans = 3;
            }
          }
          if (temp > ans) {
            res = {val, val + (1ll << i)};
            ans = 2;
          }
          temp = 1;
        }
      }
    }
    cout << ans << "\n";
    for (auto x : res) cout << x << " ";
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      b--, res = res * a;
    else
      b = b / 2, a *= a;
  }
  return res;
}
