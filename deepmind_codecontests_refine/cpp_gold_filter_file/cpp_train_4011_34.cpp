#include <bits/stdc++.h>
using namespace std;
vector<long long> razl(long long x) {
  if (x == 0) return {0};
  vector<long long> ans;
  while (x > 0) {
    ans.push_back(x % 2);
    x /= 2;
  }
  return ans;
}
void solve() {
  long long s, x;
  cin >> s >> x;
  if ((s - x) % 2 != 0 || s < x) {
    cout << 0;
    return;
  }
  long long a = (s - x) / 2;
  vector<long long> q = razl(a), w = razl(x);
  while (q.size() < w.size()) q.push_back(0);
  while (w.size() < q.size()) w.push_back(0);
  reverse(q.begin(), q.end());
  reverse(w.begin(), w.end());
  long long n = q.size();
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    if (w[i] == 1) {
      if (q[i] == 1) {
        cout << 0;
        return;
      }
      ans *= 2;
    }
  }
  if (x == s) ans -= 2;
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
