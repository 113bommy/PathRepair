#include <bits/stdc++.h>
using namespace std;
struct Yo {
  int a, b, m, idx;
  bool operator<(const Yo &other) const {
    return (a + b - m < other.a + other.b - other.m) ||
           (a + b - m == other.a + other.b - other.m && a < other.a);
  }
};
int n;
vector<pair<int, int> > ans;
vector<Yo> v;
void solve() {
  cin >> n;
  ans.clear();
  ans.resize(n + 1);
  v.clear();
  for (int i = 0; i < n; i++) {
    Yo tmp;
    cin >> tmp.a >> tmp.b >> tmp.m;
    tmp.idx = i;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  int dist = 0, mn = -1, w = -1;
  for (auto i : v) {
    if (i.a + i.b - i.m != w) {
      dist++;
      w = i.a + i.b - i.m;
      if (i.m > i.b) {
        mn = i.a - (i.m - i.b);
        ans[i.idx] = {i.m - i.b, i.b};
      } else {
        mn = i.a;
        ans[i.idx] = {0, i.m};
      }
      continue;
    }
    if (i.a - i.m > mn) {
      dist++;
      if (i.m > i.b) {
        mn = i.a - (i.m - i.b);
        ans[i.idx] = {i.m - i.b, i.b};
      } else {
        mn = i.a;
        ans[i.idx] = {0, i.m};
      }
    } else {
      ans[i.idx] = {i.a - mn, i.m - (i.a - mn)};
    }
  }
  cout << dist << "\n";
  for (int i = 0; i < n; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
