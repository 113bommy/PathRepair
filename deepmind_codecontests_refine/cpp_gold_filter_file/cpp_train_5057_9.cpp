#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> v;
  vector<long long> ans;
  set<long long> s;
  for (int i = 1; i <= sqrt(n); i++) {
    if ((n % i) == 0) v.push_back({i, (n / i)});
  }
  if ((2 * v.size()) < k)
    cout << -1;
  else {
    for (auto a : v) {
      if (s.find(a.first) == s.end()) {
        ans.push_back(a.first);
        s.insert(a.first);
      }
      if (s.find(a.second) == s.end()) {
        ans.push_back(a.second);
        s.insert(a.second);
      }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() >= k)
      cout << ans[k - 1];
    else
      cout << -1;
  }
  return 0;
}
