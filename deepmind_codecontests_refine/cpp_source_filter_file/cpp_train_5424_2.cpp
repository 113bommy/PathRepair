#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long rand(long long x, long long y) {
  return rng() % (y + 1 - x) + x;
}
string inline to_string(char c) {
  string second(1, c);
  return second;
}
template <typename T>
inline T gcd(T a, T b) {
  return a == 0 ? llabs(b) : gcd(b % a, a);
}
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using spi = pair<ll, pi>;
using dpi = pair<pi, pi>;
long long LLINF = 1e18;
int INF = 1e9 + 1e6;
int n;
map<vector<int>, int> mp;
int query(vector<int> v) {
  if (v.size() == 1) return 0;
  sort((v).begin(), (v).end());
  if (mp.find(v) != mp.end()) return mp[v];
  cout << "? " << v.size() << '\n';
  for (auto i : v) cout << i << ' ';
  cout << endl;
  int ans;
  cin >> ans;
  if (ans == -1) exit(0);
  return mp[v] = ans;
}
vector<int> cat(vector<int> v1, vector<int> v2) {
  vector<int> a;
  for (auto i : v1) a.emplace_back(i);
  for (auto i : v2) a.emplace_back(i);
  return a;
}
int query(vector<int> v1, vector<int> v2) {
  return query(cat(v1, v2)) - query(v1) - query(v2);
}
vector<int> v[(606)];
int colour[(606)], p[(606)], st[(606)], en[(606)], co;
void dfs(int x) {
  st[x] = co++;
  for (auto i : v[x]) colour[i] = colour[x] ^ 1, p[i] = x, dfs(i);
  en[x] = co - 1;
}
bool isp(int a, int b) { return st[a] <= st[b] && en[a] >= en[b]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> v1 = {1};
  vector<int> v2;
  for (ll i = 2; i <= ll(n); ++i) v2.emplace_back(i);
  while (v2.size()) {
    int st = 0, en = ll(v2.size()) - 1;
    while (st ^ en) {
      int mid = (st + en) >> 1;
      vector<int> tmp;
      for (ll i = st; i <= ll(mid); ++i) tmp.emplace_back(v2[i]);
      if (query(v1, tmp))
        en = mid;
      else
        st = mid + 1;
    }
    int ind = st;
    st = 0, en = ll(v1.size()) - 1;
    while (st ^ en) {
      int mid = (st + en) >> 1;
      vector<int> tmp;
      for (ll i = st; i <= ll(mid); ++i) tmp.emplace_back(v1[i]);
      if (query(tmp, {v2[ind]}))
        en = mid;
      else
        st = mid + 1;
    }
    v[v1[st]].emplace_back(v2[ind]);
    v1.emplace_back(v2[ind]);
    v2.erase(v2.begin() + ind);
  }
  p[1] = 1, dfs(1);
  v1.clear(), v2.clear();
  for (ll i = 1; i <= ll(n); ++i)
    if (colour[i] == 0)
      v1.emplace_back(i);
    else
      v2.emplace_back(i);
  if (query(v1) || query(v2)) {
    if (query(v1) == 0) swap(v1, v2);
    int st = -1, en = ll(v1.size()) - 1;
    while (en - st > 1) {
      int mid = (st + en) >> 1;
      vector<int> tmp;
      for (ll i = 0; i <= ll(mid); ++i) tmp.emplace_back(v1[i]);
      if (query(tmp))
        en = mid;
      else
        st = mid;
    }
    int node1 = v1[en];
    st = -1;
    while (en - st > 1) {
      int mid = (st + en) >> 1;
      vector<int> tmp = {node1};
      for (ll i = 0; i <= ll(mid); ++i) tmp.emplace_back(v1[i]);
      if (query(tmp))
        en = mid;
      else
        st = mid;
    }
    int node2 = v1[en];
    assert(node1 ^ node2);
    vector<int> ans;
    if (isp(node1, node2) || isp(node2, node1)) {
      if (isp(node2, node1)) swap(node1, node2);
      while (node2 ^ node1) {
        ans.emplace_back(node2), node2 = p[node2];
      }
      ans.emplace_back(node1);
    } else {
      while (!isp(node1, node2)) {
        ans.emplace_back(node1), node1 = p[node1];
      }
      ans.emplace_back(node1);
      reverse((ans).begin(), (ans).end());
      while (node2 ^ node1) {
        ans.emplace_back(node2), node2 = p[node2];
      }
    }
    cout << "N " << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
    cout << endl;
    return 0;
  }
  cout << "Y " << v1.size() << '\n';
  for (auto i : v1) cout << i << ' ';
  cout << endl;
}
