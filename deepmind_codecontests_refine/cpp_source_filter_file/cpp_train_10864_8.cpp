#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
long long MOD = 998244353;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first > b.first;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int a = min(x, y);
    int b = max(x, y);
    vp.push_back(make_pair(a, b));
  }
  sort(vp.begin(), vp.end(), cmp);
  int id = -1;
  vector<int> cp;
  for (auto x : vp) {
    if (x.first <= id) {
      continue;
    } else {
      cp.push_back(x.second);
      id = x.second;
    }
  }
  cout << cp.size() << endl;
  for (auto x : cp) cout << x << " ";
}
