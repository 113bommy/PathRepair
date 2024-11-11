#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
const double PI = acos(-1);
const double e = exp(1);
using namespace std;
signed main() {
  long long n, a;
  cin >> n;
  set<long long> in, out;
  vector<long long> ans;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    if ((a > 0 && out.find(a) != out.end()) || in.find(a) == in.end()) {
      cout << -1;
      return 0;
    } else if (a > 0) {
      in.insert(a);
    } else if (0 > a) {
      if (in.find(-a) == in.end()) {
        cout << -1;
        return 0;
      } else {
        in.erase(-a);
        out.insert(-a);
      }
    }
    if (in.size() == 0) {
      out.erase(out.begin(), out.end());
      ans.push_back(i + 1 - sum);
      sum = i + 1;
    }
  }
  if (in.size()) {
    cout << -1;
    return 0;
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  return 0;
}
