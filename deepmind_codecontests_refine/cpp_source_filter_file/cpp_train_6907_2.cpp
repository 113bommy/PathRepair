#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
  for (pair<T1, T2> &t : v) is >> t.first >> t.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const T &t : v) {
    os << t << " ";
  }
  os << '\n';
  return os;
}
double pi = acos(-1.0);
long long md = 1000000007;
long long abst(long long a) { return a < 0 ? -a : a; }
struct HASH {
  size_t operator()(const pair<long long, long long> &x) const {
    return (size_t)x.first * 37U + (size_t)x.second;
  }
};
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long Pow(long long n, long long x) {
  long long ans = 1;
  while (x > 0) {
    if (x & 1) ans = (ans * n) % md;
    n = (n * n) % md;
    x = x >> 1;
  }
  return ans;
}
vector<long long> fact, inv;
void inverse(long long n) {
  inv.resize(n + 1);
  inv[0] = 1;
  for (long long i = 1; i <= n; i++) inv[i] = Pow(fact[i], md - 2);
}
void factorial(long long n) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % md;
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> v[n + 1];
  while (m--) {
    long long x, y, w;
    cin >> x >> y >> w;
    v[x].push_back({y, w});
    v[y].push_back({x, w});
  }
  long long par[n + 1], dis[n + 1];
  memset(par, -1, sizeof(par));
  for (long long i = 0; i <= n; i++) dis[i] = INT_MAX;
  dis[1] = 0;
  multiset<pair<long long, long long>> s;
  s.insert({0, 1});
  while (!s.empty()) {
    pair<long long, long long> p = *s.begin();
    s.erase(s.begin());
    long long x = p.second, w = p.first;
    for (pair<long long, long long> pt : v[x])
      if (dis[pt.first] > pt.second + w) {
        par[pt.first] = x;
        dis[pt.first] = w + pt.second;
        s.insert({dis[pt.first], pt.first});
      }
  }
  if (par[n] == -1)
    cout << -1;
  else {
    stack<long long> st;
    long long x = par[n];
    st.push(n);
    while (x != -1) {
      st.push(x);
      x = par[x];
    }
    if (st.top() == 1)
      while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
      }
    else
      cout << -1;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
