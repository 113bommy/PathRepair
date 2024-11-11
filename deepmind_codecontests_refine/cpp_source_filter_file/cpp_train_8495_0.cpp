#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const double eps = 0.000001;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, v;
  cin >> n >> k;
  long long ans1 = 0;
  set<pair<int, int> > s;
  vector<int> ans(n);
  for (int i = 0; i < k; i++) {
    cin >> v;
    s.insert(make_pair(v, i));
  }
  for (int i = k; i < n; i++) {
    cin >> v;
    s.insert(make_pair(v, i));
    auto it = s.end();
    it--;
    ans[it->second] = i;
    ans1 += (long long)it->first * (i - it->second);
    s.erase(it);
  }
  for (int i = 0; i < k; i++) {
    auto it = s.end();
    it--;
    ans[it->second] = i + n;
    ans1 += (long long)it->first * (i + n - it->second);
    s.erase(it);
  }
  cout << ans1 << endl;
  for (int i : ans) cout << i + k - 1 << ' ';
  return 0;
}
