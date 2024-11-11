#include <bits/stdc++.h>
using namespace std;
long long ax, ay, bx, by, cx, cy;
set<pair<long long, long long>> res;
vector<pair<long long, long long>> p;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;
  p.push_back({ax, ay});
  p.push_back({bx, by});
  p.push_back({cx, cy});
  sort(p.begin(), p.end());
  for (long long i = p[0].first; i <= p[1].first; i++) {
    res.insert({i, p[0].second});
  }
  for (long long i = p[2].first; i >= p[1].first; i--) {
    res.insert({i, p[0].second});
  }
  long long maxi = max(max(p[0].second, p[1].second), p[2].second);
  long long mini = min(min(p[0].second, p[1].second), p[2].second);
  for (long long i = maxi; i >= mini; i--) {
    res.insert({p[1].first, i});
  }
  cout << res.size() << endl;
  for (auto i : res) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
