#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &item) {
  out << '(' << item.first << ", " << item.second << ')';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const auto &item : v) out << item << ' ';
  return out;
}
const int N = 1010;
int p[N];
ll query(int type, int i, int j, int k) {
  cout << type << ' ' << i << ' ' << j << ' ' << k << endl;
  ll ans;
  cin >> ans;
  return ans;
}
void solve(const vector<int> &v, int off) {
  if (v.empty()) return;
  vector<pll> areas;
  for (auto i : v) areas.push_back({query(1, 1, 2, i), i});
  sort(areas.rbegin(), areas.rend());
  vector<int> l, r;
  int node = areas[0].second;
  for (int i = 1; i < areas.size(); ++i)
    if (query(2, 1, node, areas[i].second) > 0)
      l.push_back(areas[i].second);
    else
      r.push_back(areas[i].second);
  reverse(l.begin(), l.end());
  int x = off;
  for (auto a : l) p[++x] = a;
  p[++x] = node;
  for (auto a : r) p[++x] = a;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v1, v2;
  for (int i = 3; i <= n; ++i)
    if (query(2, 1, 2, i) > 0)
      v1.push_back(i);
    else
      v2.push_back(i);
  p[1] = 1;
  p[1 + v1.size() + 1] = 2;
  solve(v1, 1);
  solve(v2, 1 + v1.size() + 1);
  cout << 0;
  for (int i = 1; i <= n; ++i) cout << ' ' << p[i];
  cout << '\n';
  return 0;
}
