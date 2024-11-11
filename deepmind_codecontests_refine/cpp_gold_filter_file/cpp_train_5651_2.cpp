#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_pq = priority_queue<T>;
const int inf = 2e9 + 5;
const long long l_inf = 2e18 + 5;
const int mod_v = 1e9 + 7;
const int max_n = 1e5 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
template <typename T>
tuple<T, T, T> egcd(T a, T b) {
  T x1 = 1, x2 = 0, y1 = 0, y2 = 1;
  while (b) {
    T q = a / b, r = a % b;
    T new_x = x1 - q * x2, new_y = y1 - q * y2;
    x1 = x2, y1 = y2, x2 = new_x, y2 = new_y;
    a = b, b = r;
  }
  return make_tuple(a, x1, y1);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
template <typename T>
inline T mod(T a, T b = mod_v) {
  return (a % b + b) % b;
}
template <typename T>
inline T mod_inv(T a, T b = mod_v) {
  return mod(get<1>(egcd(a, b)), b);
}
template <typename T>
inline T sum(T a, T b, T m = mod_v) {
  return mod(mod(a, m) + mod(b, m), m);
}
template <typename T>
inline T difference(T a, T b, T m = mod_v) {
  return mod(mod(a, m) - mod(b, m), m);
}
inline long long product(long long a, long long b, long long m = mod_v) {
  return mod(mod(a, m) * mod(b, m), m);
}
inline long long quotient(long long a, long long b, long long m = mod_v) {
  return mod(mod(a, m) * mod_inv(b, m), m);
}
template <typename T, typename T2>
ostream &operator<<(ostream &s, const pair<T, T2> &p) {
  return s << p.first << ' ' << p.second << ' ';
}
template <typename T, typename T2>
istream &operator>>(istream &s, pair<T, T2> &p) {
  return s >> p.first >> p.second;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  for (auto it : v) s << it << ' ';
  return s;
}
template <typename T>
istream &operator>>(istream &s, vector<T> &v) {
  for (auto it = (v).begin(), it_ = (v).end(); it != it_; ++it) s >> *it;
  return s;
}
template <typename T>
void read_range(T beg, T end) {
  while (beg != end) cin >> *beg++;
}
template <typename T>
void print_range(T beg, T end) {
  while (beg != end) cout << *beg++ << ' ';
}
struct reader {
  template <typename T>
  reader &operator,(T &v) {
    cin >> v;
    return *this;
  }
} rdr;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << ", ";
    return *this;
  }
} dbg;
unordered_map<int, vector<pair<int, int>>> adj;
unordered_map<int, int> d, c, prv;
map<pair<int, int>, int> mn, id;
int n, l;
void print_ramp() {
  int i = l;
  vector<int> ar;
  while (i) {
    if (prv[i] < i and d[i] - d[prv[i]] != i - prv[i])
      ar.push_back(id[make_pair(prv[i], i)]);
    i = prv[i];
  }
  reverse((ar).begin(), (ar).end());
  cout << ar.size() << '\n';
  cout << ar;
}
void dijkstra() {
  d[0] = 0;
  min_pq<pair<int, int>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    int u = pq.top().second, dist = pq.top().first;
    pq.pop();
    if (d.find(u) != d.end() and d[u] < dist) continue;
    for (auto &a : adj[u]) {
      int v = a.first, w = a.second;
      if (d.find(v) == d.end() or d[u] + w < d[v]) {
        d[v] = d[u] + w;
        prv[v] = u;
        pq.emplace(d[v], v);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> l;
  vector<int> ar{0, l};
  for (int i = 0, i_ = (n); i < i_; ++i) {
    int x, d, t, p;
    rdr, x, d, t, p;
    ;
    if (x - p >= 0) {
      ar.push_back(x - p);
      ar.push_back(x + d);
      adj[x - p].emplace_back(x + d, p + t);
      if (mn.find(make_pair(x - p, x + d)) == mn.end() or
          mn[make_pair(x - p, x + d)] > p + t) {
        id[make_pair(x - p, x + d)] = i + 1;
        mn[make_pair(x - p, x + d)] = p + t;
      }
    }
  }
  sort((ar).begin(), (ar).end());
  ar.erase(unique((ar).begin(), (ar).end()), ar.end());
  adj[ar[0]].emplace_back(ar[1], ar[1] - ar[0]);
  for (int i = 1; i < ar.size() - 1; ++i) {
    adj[ar[i]].emplace_back(ar[i + 1], ar[i + 1] - ar[i]);
    adj[ar[i]].emplace_back(ar[i - 1], ar[i] - ar[i - 1]);
  }
  dijkstra();
  cout << d[l] << '\n';
  print_ramp();
  return 0;
}
