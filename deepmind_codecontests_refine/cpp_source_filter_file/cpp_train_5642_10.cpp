#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  unordered_map<char, int> map1;
  int l = 0, r = l + d - 1;
  for (int i = l; i <= r; i++) {
    map1[v[i]]++;
  }
  int ans = map1.size();
  int minAns = ans;
  l++, r++;
  while (r < n) {
    if (map1[v[l - 1]]) {
      map1[v[l - 1]]--;
      if (!map1[v[l - 1]]) ans--;
    }
    if (map1[v[r]]) {
      map1[v[r]]++;
    } else {
      ans++;
      map1[v[r]]++;
    }
    l++, r++;
    minAns = min(minAns, ans);
  }
  cout << minAns << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
