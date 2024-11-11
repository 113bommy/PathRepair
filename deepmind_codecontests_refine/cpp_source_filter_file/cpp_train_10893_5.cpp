#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long int N = 1e5 + 5;
long long int mod = 998244353;
long long int dx[4] = {0, 0, +1, -1};
long long int dy[4] = {+1, -1, 0, 0};
map<char, long long int> mp, p;
void solve() {
  long long int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    p[s[0]] = 1;
    long long int tmp = 1;
    for (long long int i = (long long int)s.size() - 1; i >= 0; i--) {
      mp[s[i]] += tmp;
      tmp *= 10;
    }
  }
  vector<pair<long long int, char> > vp;
  for (auto to : mp) {
    vp.push_back({to.second, to.first});
  }
  sort(vp.rbegin(), vp.rend());
  char c;
  for (long long int i = 0; i < (long long int)vp.size(); i++) {
    if (p.find(vp[i].second) == p.end()) {
      c = vp[i].second;
      break;
    }
  }
  long long int yan = 1, tt = 0;
  for (long long int i = 0; i < (long long int)vp.size(); i++) {
    if (vp[i].second == c) continue;
    tt += (vp[i].first) * yan;
    yan++;
  }
  cout << tt << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) solve();
  return 0;
}
