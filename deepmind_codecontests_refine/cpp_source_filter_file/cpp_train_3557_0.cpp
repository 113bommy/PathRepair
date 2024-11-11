#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, mod = 1e9 + 7;
const long long inf = 1e18;
vector<int> v[maxn];
vector<pair<pair<int, int>, int> > ans;
pair<pair<int, int>, int> ed[maxn];
pair<int, int> fnd(int u, int par) {
  pair<int, int> p = {u, u};
  for (int y : v[u]) {
    if (y != par) {
      pair<int, int> pp = fnd(y, u);
      if (p.first == u)
        p.first = pp.first;
      else if (p.second == u)
        p.second = pp.first;
      else
        break;
    }
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(b);
    v[b].push_back(a);
    ed[i] = {{a, b}, c / 2};
  }
  for (int i = 1; i <= n; i++) {
    if (int((v[i]).size()) == 2) return cout << "NO\n", 0;
  }
  for (int i = 0; i < n - 1; i++) {
    pair<int, int> A = fnd(ed[i].first.first, ed[i].first.second);
    pair<int, int> B = fnd(ed[i].first.second, ed[i].first.first);
    ans.push_back({{A.first, B.first}, -ed[i].second});
    ans.push_back({{A.second, B.second}, -ed[i].second});
    if (A.first != A.second) ans.push_back({A, ed[i].second});
    if (B.first != B.second) ans.push_back({B, ed[i].second});
  }
  cout << "YES\n" << int((ans).size()) << "\n";
  for (auto x : ans) {
    cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
  }
  return 0;
}
