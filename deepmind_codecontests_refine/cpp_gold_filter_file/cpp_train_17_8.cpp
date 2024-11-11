#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  long long n = 0;
  cin >> n;
  deque<long long> posl(n);
  for (auto& p : posl) cin >> p;
  map<long long, long long> al;
  for (auto& p : posl) al[p]++;
  long long m = 0;
  cin >> m;
  for (long long k = 0; k < m; k++) {
    long long q = 0, pos = 0, sum = 0, num = 0, need = 0;
    cin >> q >> pos;
    auto it = al.end(), ed = al.begin();
    it--, ed--;
    for (it; it != ed; it--) {
      if (sum + it->second < q)
        sum += it->second;
      else {
        need = q - sum;
        num = it->first;
        break;
      }
    }
    deque<long long> ans;
    for (auto& p : posl) {
      if (p == num && need > 0)
        ans.push_back(p), need--;
      else if (p > num)
        ans.push_back(p);
    }
    cout << ans[pos - 1] << "\n";
  }
  return 0;
}
