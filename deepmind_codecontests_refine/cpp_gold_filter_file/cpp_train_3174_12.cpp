#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
long long x[N], d[N];
long long dpl[N], dpr[N];
template <class T>
bool uin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int _n(n + 2), i(0); i < _n; i++) cin >> x[i];
  for (int _n(n + 1), i(1); i < _n; i++) cin >> d[i];
  d[0] = d[n + 1] = 2e9;
  multiset<pair<long long, long long>> del;
  multiset<long long> val;
  for (int _n(n + 1), i(0); i < _n; i++) dpl[i] = x[0];
  for (int _n(n + 1), i(1); i < _n; i++) {
    while (!del.empty() && del.begin()->first < x[i]) {
      long long v = del.begin()->second;
      del.erase(del.begin());
      val.erase(val.find(v));
    }
    if (!del.empty()) dpl[i] = *val.rbegin();
    if (dpl[i] + 2 * d[i] > x[i]) {
      val.insert(x[i]);
      del.insert(make_pair(dpl[i] + 2 * d[i], x[i]));
    }
    if (dpl[i] + 2 * d[i] >= x[n + 1]) {
      cout << 0 << endl;
      return 0;
    }
  }
  del.clear();
  val.clear();
  for (int _n(n + 1), i(0); i < _n; i++) dpr[i] = x[n + 1];
  for (int i = n; i >= 1; --i) {
    while (!del.empty() && del.rbegin()->first > x[i]) {
      auto p = *del.rbegin();
      del.erase(del.find(p));
      val.erase(val.find(p.second));
    }
    if (!del.empty()) dpr[i] = *val.begin();
    if (dpr[i] - 2 * d[i] < x[i]) {
      val.insert(x[i]);
      del.insert(make_pair(dpr[i] - 2 * d[i], x[i]));
    }
  }
  vector<pair<long long, long long>> stl, str;
  for (int _n(n + 1), i(0); i < _n; i++) {
    long long y = 2 * d[i] + dpl[i];
    if (y <= x[i]) {
      continue;
    }
    while (!stl.empty() && stl.back().first <= y) stl.pop_back();
    stl.push_back(make_pair(y, x[i]));
  }
  for (int i = n + 1; i > 0; --i) {
    long long y = dpr[i] - 2 * d[i];
    if (y >= x[i]) continue;
    while (!str.empty() && str.back().first >= y) str.pop_back();
    str.push_back(make_pair(y, x[i]));
  }
  long long ans = 2e9;
  int j = (int)str.size() - 1;
  for (int _n((int)stl.size()), i(0); i < _n; i++) {
    while (j && str[j].first > stl[i].first) --j;
    if (str[j].first <= stl[i].first && str[j].second > stl[i].second)
      uin(ans, str[j].second - stl[i].second);
  }
  cout << 0.5 * ans << '\n';
  return 0;
}
