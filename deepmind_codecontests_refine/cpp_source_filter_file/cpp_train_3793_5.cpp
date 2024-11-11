#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
void solve() {
  long long n;
  cin >> n;
  vector<multiset<pair<long long, long long> > > a(n);
  long long k;
  cin >> k;
  multimap<long long, long long> d;
  vector<long long> dis;
  long long s = -1;
  for (long long i = 0; i < n; i++) {
    long long q;
    cin >> q;
    if (q == 0) {
      if (s == -1)
        s = i;
      else {
        cout << -1 << endl;
        return;
      }
    } else
      d.insert({q, i});
  }
  if (s == -1) {
    cout << -1 << endl;
    return;
  }
  a[0].insert({0, s});
  set<pair<long long, long long> > ans;
  for (auto it : d) {
    if (a[it.first - 1].size() == 0) {
      cout << -1 << endl;
      return;
    }
    if (a[it.first - 1].begin()->first < k) {
      ans.insert({a[it.first - 1].begin()->second, it.second});
      pair<long long, long long> cw = *a[it.first - 1].begin();
      a[it.first - 1].erase(a[it.first - 1].begin());
      a[it.first - 1].insert({cw.first + 1, cw.second});
      a[it.first].insert({0, it.second});
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first + 1 << ' ' << it.second + 1 << endl;
  }
}
int main() {
  solve();
  return 0;
}
