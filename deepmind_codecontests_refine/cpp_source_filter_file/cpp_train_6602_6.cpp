#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
const int N = 1000000;
long long n;
long long fl(long long x, long long y) {
  return 1 <= x && x <= n && 1 <= y && y <= n;
}
vector<long long> xx;
map<long long, vector<long long> > keko;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    xx.push_back(x);
    keko[x].push_back(y);
  }
  keko[n].push_back(n + 1);
  xx.push_back(n);
  sort(xx.begin(), xx.end());
  xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
  for (auto x : xx) {
    keko[x].push_back(0);
    keko[x].push_back(n + 1);
    sort(keko[x].begin(), keko[x].end());
  }
  set<pair<long long, long long> > otr;
  long long lst = 1;
  otr.insert({1, 1});
  if (keko[1].size()) {
    otr.clear();
    otr.insert({1, keko[1][1] - 1});
  }
  for (auto x : xx) {
    if (!otr.size()) {
      cout << -1;
      return 0;
    }
    if (x <= lst) {
      continue;
    }
    if (x != lst + 1) {
      long long mn = (*(otr.begin())).first;
      otr.clear();
      otr.insert({mn, n});
    }
    lst = x;
    auto it = otr.begin();
    set<pair<long long, long long> > otr2;
    for (auto hv : keko[x]) {
      long long mn = MOD;
      while (it != otr.end() && it->second < hv) {
        mn = min(mn, it->first);
        it++;
      }
      if (mn != MOD) otr2.insert({mn, hv - 1});
      if (it != otr.end() && it->first <= hv) {
        if (it->first != hv) {
          otr2.insert({it->first, hv - 1});
        }
        long long sc = it->second;
        otr.erase(it);
        if (sc > hv) otr.insert({hv + 1, sc});
        it = otr.lower_bound({hv + 1, sc});
      }
    }
    otr.clear();
    otr = otr2;
  }
  if (!otr.size()) {
    cout << -1;
    return 0;
  }
  auto it = otr.end();
  it--;
  if (it->second < n) {
    cout << -1;
    return 0;
  }
  cout << 2 * (n - 1);
}
