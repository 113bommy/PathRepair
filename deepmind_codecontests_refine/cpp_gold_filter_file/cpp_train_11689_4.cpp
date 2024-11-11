#include <bits/stdc++.h>
const long long N = 1e5 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 998244353;
const long long xesh = 31;
using namespace std;
long long a[N], a1[N], b[N], b1[N], ans1, mx, n;
vector<pair<long long, long long> > ans;
int main() {
  ios_base::sync_with_stdio(0);
  long long o = 1;
  while (o--) {
    cin >> n;
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
      cin >> a1[i];
    }
    ans1 = INF;
    mx = min(a[0], a1[1]) + min(a[1], a1[2]) + min(a[2], a1[0]);
    ans.push_back({0, 0});
    ans.push_back({0, 2});
    ans.push_back({1, 1});
    ans.push_back({1, 0});
    ans.push_back({2, 2});
    ans.push_back({2, 1});
    sort(ans.begin(), ans.end());
    while (next_permutation(ans.begin(), ans.end())) {
      for (int i = 0; i < 3; i++) {
        b[i] = a[i];
      }
      for (int i = 0; i < 3; i++) {
        b1[i] = a1[i];
      }
      for (int i = 0; i < ans.size(); i++) {
        int cnt = min(b[ans[i].first], b1[ans[i].second]);
        b[ans[i].first] -= cnt;
        b1[ans[i].second] -= cnt;
      }
      long long cur = min(b[0], b1[1]) + min(b[1], b1[2]) + min(b[2], b1[0]);
      ans1 = min(ans1, cur);
    }
    cout << ans1 << "\n" << mx << "\n";
  }
}
