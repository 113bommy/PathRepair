#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> V(n), T(n);
  for (long long& v : V) cin >> v;
  for (long long& t : T) cin >> t;
  multiset<long long> q;
  long long pref_sum = 0;
  for (long long i = 0; i < n; ++i) {
    long long ans = 0;
    q.insert(pref_sum + V[i]);
    while (q.size()) {
      if (*q.begin() <= pref_sum + T[i]) {
        ans += (*q.begin() - pref_sum);
        q.erase(q.begin());
      } else {
        break;
      }
    }
    pref_sum += T[i];
    ans += q.size() * T[i];
    cout << ans << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
