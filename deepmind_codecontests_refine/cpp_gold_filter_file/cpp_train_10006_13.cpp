#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 1e5 + 14;
const long long inf = (long long)1e18 + 10;
const long long mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
long long n;
set<pair<long long, long long>> used;
map<pair<long long, long long>, long long> mp;
set<pair<long long, pair<long long, long long>>,
    greater<pair<long long, pair<long long, long long>>>>
    st;
vector<pair<long long, long long>> moves = {
    {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};
vector<pair<long long, long long>> ans;
void addv(pair<long long, long long> p) {
  used.insert(p);
  for (auto mv : moves) {
    long long nx = p.first + mv.first;
    long long ny = p.second + mv.second;
    pair<long long, pair<long long, long long>> tmp =
        make_pair(mp[{nx, ny}], make_pair(nx, ny));
    if (st.find(tmp) != st.end()) st.erase(tmp);
    ++mp[{nx, ny}];
    ++tmp.first;
    st.insert(tmp);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  cin >> n;
  if (n < 15) {
    used.emplace(0, 0);
    ans.emplace_back(0, 0);
    --n;
    for (auto p : moves) {
      ++mp[p];
      st.emplace(1, p);
    }
    while (n) {
      auto pp = *st.begin();
      auto p = pp.second;
      if (used.find(p) != used.end()) continue;
      if (pp.first >= 4)
        addv(p);
      else {
        long long ncnt = 4 - pp.first;
        for (auto mv : moves) {
          if (!ncnt || !n) break;
          long long nx = p.first + mv.first;
          long long ny = p.second + mv.second;
          if (used.find({nx, ny}) == used.end()) {
            --ncnt;
            --n;
            addv({nx, ny});
            ans.emplace_back(nx, ny);
          }
        }
        if (!ncnt) addv(p);
      }
      st.erase(st.begin());
    }
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
  } else {
    long long cx = 0, cy = 0;
    --n;
    ans.emplace_back(cx, cy);
    long long per = n / 4;
    long long rest = n % 4;
    for (long long i = 1; i <= per; ++i) ans.emplace_back(cx + i, cy);
    for (long long i = 1; i <= per; ++i) ans.emplace_back(cx - i, cy);
    for (long long i = 1; i <= per; ++i) ans.emplace_back(cx, cy + i);
    for (long long i = 1; i <= per; ++i) ans.emplace_back(cx, cy - i);
    if (rest) {
      --rest;
      ans.emplace_back(cx + per + 1, cy);
    }
    if (rest) {
      --rest;
      ans.emplace_back(cx - per - 1, cy);
    }
    if (rest) {
      --rest;
      ans.emplace_back(cx, cy + per + 1);
    }
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
  }
}
