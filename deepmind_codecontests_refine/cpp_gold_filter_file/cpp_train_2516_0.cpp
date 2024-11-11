#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
pair<int, int> dp[N];
struct D {
  int k, x, id;
  bool operator<(const D &t) const {
    if (x == t.x) return k < t.k;
    return x > t.x;
  }
};
vector<D> v;
pair<int, int> a[N];
int n, m;
int main() {
  cin >> n;
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    v.push_back(D{1, a[i].first, i});
    v.push_back(D{0, a[i].second, i});
  }
  sort(v.begin(), v.end());
  pair<int, int> cur = make_pair(0x3f3f3f3f, 0);
  for (auto &p : v) {
    if (p.k) {
      if (cur.first == 0x3f3f3f3f)
        dp[p.id] = make_pair(a[p.id].second, 1);
      else {
        int left = cur.first - (a[p.id].first - a[p.id].second);
        dp[p.id] = make_pair(left, cur.second);
      }
    } else {
      if (dp[p.id].first < cur.first)
        cur = dp[p.id];
      else if (dp[p.id].first == cur.first)
        cur.second = (cur.second + dp[p.id].second) % mod;
    }
  }
  cout << cur.second << endl;
}
