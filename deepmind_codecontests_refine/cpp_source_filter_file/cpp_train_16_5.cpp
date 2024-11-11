#include <bits/stdc++.h>
using namespace std;
void jakos() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
const int mod = 1e9 + 7;
const int base = 179;
const int INF = 1e9;
const int N = 1e5;
signed main() {
  jakos();
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a.emplace_back(b, i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int q;
  cin >> q;
  while (q--) {
    vector<pair<int, int>> ans;
    int k, pos;
    cin >> k >> pos;
    for (int i = 0; i < k; i++) {
      ans.emplace_back(a[i].second, a[i].first);
    }
    sort(ans.begin(), ans.end());
    cout << ans[pos - 1].second << endl;
  }
  return 0;
}
