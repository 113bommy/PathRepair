#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
const ll INF = numeric_limits<ll>::max(), MOD = 1e9 + 7;
const int INF_i = numeric_limits<int>::max(), MAX = 1e6;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vii v(n);
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
  map<int, vector<pii>> m;
  for (int r = 0; r < n; r++) {
    for (int l = r, s = 0; l >= 0; l--) {
      s += v[l];
      m[s].push_back({l + 1, r + 1});
    }
  }
  vector<pii> res;
  for (auto p : m) {
    vector<pii> ans;
    int prev = -1;
    for (pii seg : p.second) {
      if (seg.first <= prev) continue;
      ans.push_back(seg);
      prev = seg.second;
    }
    if (res.size() < ans.size()) res = ans;
  }
  cout << res.size() << '\n';
  for (pii p : res) {
    cout << p.first << ' ' << p.second << '\n';
  }
}
