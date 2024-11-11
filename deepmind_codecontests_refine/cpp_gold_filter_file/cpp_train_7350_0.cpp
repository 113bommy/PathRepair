#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-14;
const long long maxn = 100500;
const long long mod = 1e9 + 7;
long long n, m;
long long k;
vector<pair<long long, long long> > pos;
vector<pair<pair<long long, long long>, long long> > pt;
pair<long long, long long> sweep(long long T) {
  map<long long, vector<pair<long long, long long> > > op;
  map<long long, vector<pair<long long, long long> > > clo;
  set<long long> event;
  for (auto p : pos) {
    long long a = max(1LL, p.first - T), b = max(1LL, p.second - T);
    long long c = min(n, p.first + T), d = min(m, p.second + T);
    op[a].push_back({b, d});
    clo[c + 1].push_back({b, d});
    event.insert(a);
    event.insert(c + 1);
  }
  multiset<pair<long long, long long> > st;
  pair<long long, long long> rs = {n + 1, m + 1};
  if (*event.begin() != 1) return {1, 1};
  for (auto e : event) {
    if (e > n) break;
    for (auto p : op[e]) st.insert(p);
    for (auto p : clo[e]) st.erase(st.find(p));
    if (st.empty() || st.begin()->first != 1)
      rs.first = min(rs.first, e), rs.second = 1;
    if (st.empty()) continue;
    auto L = *st.begin();
    for (auto p : st)
      if (p.first <= L.second)
        L.second = max(L.second, p.second);
      else {
        if (p.first == L.second + 1)
          L = p;
        else
          break;
      }
    if (L.second != m)
      rs.first = min(rs.first, e), rs.second = min(rs.second, L.second + 1);
  }
  if (rs.first == n + 1) rs = {-1, -1};
  return rs;
}
bool can(long long T) {
  auto rs = sweep(T);
  if (rs.first == -1) return true;
  pos.push_back({min(n, rs.first + T), min(m, rs.second + T)});
  rs = sweep(T);
  pos.pop_back();
  return rs.first == -1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  pos.resize(k);
  for (auto &x : pos) cin >> x.first >> x.second;
  long long lo = 0, hi = 1e9;
  while (lo <= hi) {
    long long mid = (lo + hi) >> 1;
    if (can(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << hi + 1 << '\n';
  return 0;
}
